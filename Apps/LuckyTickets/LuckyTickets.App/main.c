﻿/**
 * Lucky tickets and probability of reception
 */
#include <stdio.h>
#include <stdlib.h>

/* forward declarations */
static unsigned long int getLuckyThreshold(const unsigned int halfTicketNum);
static unsigned int calculateIndividualNumberSum(unsigned int number);

/**
 * \brief Entry point
 * \return Exit code
 */
int main()
{   
   unsigned int numCount; /* lucky ticket length */
   unsigned long int thresholdNumber; /* maximum number for a half ticket number */

   puts("Enter the even number (greater or equal 4) to calculate lucky tickets");
   scanf_s("%u", &numCount);

   if (numCount % 2 == 0 && numCount >= 4)
   {
      thresholdNumber = getLuckyThreshold(numCount / 2);

      for (size_t i = 1; i <= thresholdNumber; ++i)
      {
         printf("Separated number's sum of %d is:\t%d\n", i, calculateIndividualNumberSum(i));
      }
   }
   else
   {
      puts("Entered number is incorrect");
   }

   return 0;
}

/**
 * \brief Get the lucky - ticket threshold value
 * \details For example, for value 3 maximum lucky ticket is 999999,
 * so the threshold value is 999
 * \param halfTicketNum - Half ticket number
 * \return Ticket threshold value
 */
static unsigned long int getLuckyThreshold(const unsigned int halfTicketNum)
{
   /* Local declarations */
   char* thresholdPackedStr;
   unsigned long int thresholdNumber;

   /* Code */
   thresholdPackedStr = (char*)malloc(halfTicketNum * sizeof(char));
   for (size_t i = 0; i < halfTicketNum; ++i)
   {
      thresholdPackedStr[i] = '9'; // *(thresholdPackedStr + i) = '9';
   }

   thresholdNumber = strtol(thresholdPackedStr, NULL, 0);
   free(thresholdPackedStr);

   return thresholdNumber;
}

/**
 * \brief Calculate individual number summary
 * \details For example separated sum for 1234 is 1+2+3+4=10
 * \param number - Number to be separately calculated
 * \return Individual number summary
 */
static unsigned int calculateIndividualNumberSum(unsigned int number)
{
   /* Local declarations */
   unsigned int separatedSum = 0;
   unsigned int stepAccumulator;

   /* Code */
   do
   {
      stepAccumulator = number % 10;
      number = (unsigned int)((double)number / 10);
      separatedSum += stepAccumulator;
   }
   while (number != 0);

   return separatedSum;
}
