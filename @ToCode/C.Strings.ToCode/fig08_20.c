// Fig. 8.20: fig08_20.c
// Using function strchr
#include <stdio.h>
#include <string.h>

int main(void)
{
   const char *string = "This is a test"; // initialize char pointer 
   char character1 = 'a'; // initialize character1
   char character2 = 'z'; // initialize character2
   
   // if character1 was found in string
   if (strchr(string, character1) != NULL) {
      printf("\'%c\' was found in \"%s\".\n", 
         character1, string);
   } 
   else { // if character1 was not found
      printf("\'%c\' was not found in \"%s\".\n", 
         character1, string);
   } 

   // if character2 was found in string
   if (strchr(string, character2) != NULL) {
      printf("\'%c\' was found in \"%s\".\n", 
         character2, string);
   } 
   else { // if character2 was not found
      printf("\'%c\' was not found in \"%s\".\n", 
         character2, string);
   } 
} 
