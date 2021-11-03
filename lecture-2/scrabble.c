#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2) {
        printf("Player 1 wins!");
    } else if (score1 < score2) {
        printf("Player 2 wins!");
    } else {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    int length = strlen(word);
    int number_of_points = 0;
    for (int i = 0; i < length; i++)
    {
        int character = toupper(word[i]); //turn character to uppercase
        printf("char is %i\n", character);
        if (character < 91 && character > 64) { //if char is between A-Z
            int index_points = character - 65; //map to the points array
            printf("index is %i\n", index_points);
            printf("points is %i\n", POINTS[index_points]);
            number_of_points += POINTS[index_points];
        } else {
            //
        }
    }
    return number_of_points;
}
