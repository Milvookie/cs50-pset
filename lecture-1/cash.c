#include <math.h>
#include <stdio.h>
#include "cs50.h"

int number_of_coins(int cents);

int main(void)
{
    float change;
    do
    {
        change = get_float("Change owed:");
    } while (change < 0);

    int cents = round(change * 100);
    printf("%i\n", number_of_coins(cents));
}

int number_of_coins(int cents)
{
    int coins = 0;
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    do
    {
        if (cents >= quarters)
        {
            cents = cents - quarters;
            coins++;
        }
        else if (cents >= dimes)
        {
            cents = cents - dimes;
            coins++;
        }
        else if (cents >= nickels)
        {
            cents = cents - nickels;
            coins++;
        }
        else
        {
            cents = cents - pennies;
            coins++;
        }
    } while (cents != 0);
    return coins;
}

//get user input
//if input is negative, prompt again
//turn input to cent (remove floating point)
//function to calculate number of coins
//print number of coin