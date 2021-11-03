#include <stdio.h>
#include "cs50.h"

int main(int argc, char* argv[]) {
    if( argc == 2 ) {
      printf("argv %s\n", argv[1]);
   }
   else {
       printf("Usage: ./caesar key\n");
      return 1;
   }
    
}
//check if there is exactly one command line argument
//check if command-line argument is a positive int
//get the int command-line arg into a variable in main
//prompt user for text string
//function to cipher text string (take two arg: text and key)
//function, for each character in the
//check if char uppercase or lowercase, rotate accordingly
//if char is not a letter, print as it is