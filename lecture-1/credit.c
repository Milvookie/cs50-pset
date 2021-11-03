#include <math.h>
#include <stdio.h>
#include "cs50.h"

int number_of_digits(long int number);
int get_first_digits(long int n);
bool is_card_valid(long int card_number);

int main(void)
{
    //prompt user for input
    long int card_number = get_long("Number:");

    //has the number valid number of digit ? 13 / 15 / 16 ?
    int digits_number = number_of_digits(card_number);
    if (digits_number == 13 || digits_number == 15 || digits_number == 16) {
        int first_digits = get_first_digits(card_number);
        if (digits_number == 15 && (first_digits == 34 || first_digits == 37)) {
            if (is_card_valid(card_number)) {
                printf("AMEX\n");
            } else {
                printf("INVALID\n");
            }
        } else if ((digits_number == 13 || digits_number == 16) && (first_digits / 10) == 4) {
            if (is_card_valid(card_number)) {
                printf("VISA\n");
            } else {
                printf("INVALID\n");
            }
        } else if (digits_number == 16 && (first_digits > 50 && first_digits < 56)) {
            if (is_card_valid(card_number)) {
                printf("MASTERCARD\n");
            } else {
                printf("INVALID\n");
            }
        } else {
            printf("INVALID\n");
        }
        
    } else {
        printf("INVALID\n");
    }
    
}

int number_of_digits(long int number)
{
    int length = floor(log10(number)) + 1;
    return length;
}

int get_first_digits(long int n)
{
    while (n >= 100)
    {
        n /= 10;
    }
    return n;
}

bool is_card_valid(long int card_number)
    {
        int sum_x = 0;
        int sum_y = 0;
        while (card_number > 0)
        {
            
            long int x = card_number / 10;
            x = x % 10; //get right digit
            x = x*2;
            if (x >= 10) {
                sum_x += 1 + (x - 10);
            } else {
                sum_x += x;
            }
            long int y = card_number % 10;
            sum_y += y;
            card_number = card_number / 100;
        }
        int z = sum_x + sum_y;
        if (z % 10 == 0) {
            return true;
        } else {
            return false;
        }
    }
