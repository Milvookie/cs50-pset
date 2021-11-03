#include <stdio.h>
#include <math.h>
#include "cs50.h"
string mario(int height);
int main(void)
{
   //prompt user for int between 1 and 8
   int pyramide_size;
   do
   {
      pyramide_size = get_int("Height:");
   } while (pyramide_size < 1 || pyramide_size > 8);

   mario(pyramide_size);
}

//function make pyramide
string mario(int height)
{
   for (int i = 0; i < height; i++)
   {
      //make space before hash
      int space = height - 1 - i;
      for (int k = space; k > 0; k--)
      {
         printf(" ");
      }
      //print first part of pyramide
      for (int j = 0; j < i + 1; j++)
      {

         printf("#");
      }
      //print space between 2 parts of pyramide
      printf("  ");
      //print second part of pyramide
      for (int j = 0; j < i + 1; j++)
      {
         printf("#");
      }
      //return to ligne
      printf("\n");
   }
}