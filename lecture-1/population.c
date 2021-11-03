#include "cs50.h"
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size
    //has to be sup to 9, prompt again if not
    int start_size;
    do
    {
        start_size = get_int("Starting pop size:");
    } while (start_size < 9);

    // TODO: Prompt for end size
    // if inf to starting size, prompt again
    int end_size;
    do
    {
        end_size = get_int("Ending pop size:");
    } while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    int nb_of_years = 0;
    int pop_size = start_size;
    do
    {
        if (pop_size == end_size)
        {
        }
        else
        {
            pop_size = pop_size + (pop_size / 3) - (pop_size / 4);
            trunc(pop_size);
            nb_of_years++;
        }

    } while (pop_size < end_size);

    // TODO: Print number of years
    printf("Years: %i\n", nb_of_years);
}