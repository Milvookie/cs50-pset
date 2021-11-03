#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int get_reading_grade(string text);

int main(void)
{
    string text = get_string("Text:");
    int grade = get_reading_grade(text);
    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade > 15) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", grade);
    }    
}

int get_reading_grade(string text)
    {
        int count = strlen(text); //get length of the text string
        //init variables needed for Coleman-Liau formula
        int letters = 0;
        int words = 1;
        int sentences = 0;
        //for each character in the string
        for (int i = 0; i < count; i++)
        {
            int upper_char = toupper(text[i]);
            if (upper_char < 91 && upper_char > 64)
            { //look if is letter (ASCII)
                letters++;
            }
            else
            { //look at the character
                if (text[i] == 32)
                {
                    words++;
                }
                else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
                {
                    sentences++;
                }
            }
        }
        float L = (float)letters / words * 100;
        float S = (float)sentences / words * 100;
        float index = 0.0588 * L - 0.296 * S - 15.8;
        int grade = round(index);
        return grade;
    }