﻿#include "parser.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void start_evaluation(double* answer)
{
   get_token();
   if (!*token)
   {
      set_error(2);
      return;
   }

   eval_add_or_subtract(answer);

   if (*token)
   {
      set_error(0); /* Последней лексемой должен быть нуль */
   }
}

void eval_add_or_subtract(double* answer)
{
   register char op;
   double temp;

   eval_multiply_or_divide(answer);
   while ((op = *token) == '+' || op == '-')
   {
      get_token();
      eval_multiply_or_divide(&temp);
      switch (op)
      {
      case '-':
         *answer = *answer - temp;
         break;

      case '+':
         *answer = *answer + temp;
         break;

      default:
         break;
      }
   }
}

void eval_multiply_or_divide(double* answer)
{
   register char op;
   double temp;

   eval_power(answer);
   while ((op = *token) == '*' || op == '/' || op == '%')
   {
      get_token();
      eval_power(&temp);
      switch (op)
      {
      case '*':
         *answer = *answer * temp;
         break;

      case '/':
         if (temp == 0.0)
         {
            set_error(3); /* Деление на 0 */
            *answer = 0.0;
         }
         else
         {
            *answer = *answer / temp;
         }

         break;

      case '%':
         *answer = (int)*answer % (int)temp;
         break;

      default:
         break;
      }
   }
}

void eval_power(double* answer)
{
   double temp;

   eval_unary_plus_minus(answer);

   if (*token == '^')
   {
      get_token();
      eval_power(&temp);
      const double ex = *answer;
      if (temp == 0.0)
      {
         *answer = 1.0;
         return;
      }

      for (register int t = (int)temp - 1; t > 0; --t)
      {
         *answer = (*answer) * (double)ex;
      }
   }
}

void eval_unary_plus_minus(double* answer)
{
   register char op = 0;
   if (token_type == DELIMETER && *token == '+' || *token == '-')
   {
      op = *token;
      get_token();
   }

   eval_brackets(answer);

   if (op == '-')
   {
      *answer = -(*answer);
   }
}

void eval_brackets(double* answer)
{
   if (*token == '(')
   {
      get_token();
      eval_add_or_subtract(answer);
      if (*token != ')')
      {
         set_error(1);
      }

      get_token();
   }
   else
   {
      atom(answer);
   }
}

void atom(double* answer)
{
   if (token_type == NUMBER)
   {
      *answer = atof(token); // NOLINT
      get_token();
      return;
   }

   set_error(0); /* иначе синтаксическая ошибка в выражении */
}

void get_token()
{
   token_type = 0;
   register char* temp = token;
   *temp = '\0';
   const char* delimeters = "+-*/%^=()";

   if (!*prog)
   {
      return; /* Конец выражения */
   }

   while (isspace(*prog))
   {
      /* пропустить пробелы, символы табуляции и пустой строки */
      ++prog;
   }
   
   if (strchr(delimeters, *prog))
   {
      token_type = DELIMETER;

      /* Перейти к следующему символу */
      *temp++ = *prog++;
   }
   else if (isalpha(*prog))
   {
      while (!is_delim(*prog))
      {
         *temp++ = *prog++;
      }

      token_type = VARIABLE;
   }
   else if (isdigit(*prog))
   {
      while (!is_delim(*prog))
      {
         *temp++ = *prog++;
      }

      token_type = NUMBER;
   }

   *temp = '\0';
}

void put_back()
{
   char* t = token;
   for (; *t; t++)
   {
      prog--;
   }
}

void set_error(const int error)
{
   static char* e[] =
   {
      "Syntax error",
      "Unbalanced brackets",
      "No expression",
      "Dividing by zero"
   };

   printf("%s\n", e[error]);
}

int is_delim(const char c)
{
   return strchr(" +-/*%^=()", c) || c == 9 || c == '\r' || c == 0
             ? 1
             : 0;
}
