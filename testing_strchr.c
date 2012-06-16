/*
 ============================================================================
 Name        : testing_strchr.c
 Author      : Simarpreet Singh
 Version     : v1.0
 Copyright   : GNU GPL License v3.0
 Description : Testing how strchr and strrchr work.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>     //strchr() does work without this but might result in warnings.

int main(void)
{
  // ----------------------------------------------
  // Testing for strchr().
  // ----------------------------------------------

  char str[] = "This is a sample string";
  char *pch;
  printf ("Looking for the 's' character in \"%s\"...\n",str);
  pch = strchr(str,'s');        // strchr() takes in the pointer to the string and the target entity.
  while (pch!=NULL)
  {
      /* The reason to do pch-str+1 is because the actual value of ptr and str
       * are memory addresses and we have to take the relative difference to
       * get the position value.
       *
       * +1 is done since C is a zero based index.
       *
       *  try out the following to see what happens..
       *  printf ("Value of str = %d \n", str);
       *  printf ("Value of ptr = %d \n", pch);
       *
       */

      /* This is non trivial,
       * Three statements that look almost the same behave totally different.
       * (1) = pch = strchr(pch+1, 's');  -- advances to the next location. Works
       * (2) = pch = strchr(pch++, 's');  -- post-evaluation, program crashes for some reason.
       * (3) = pch = strchr(++pch, 's');  -- pre-evaluation, does work as expected.
       */

      printf ("[strchr()] found at %d\n",pch-str+1);
      pch = strchr(++pch, 's'); // advances the pointer to the next location.

  }

  return EXIT_SUCCESS;
}
