#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // DataType => 2 tables one with the letters and the second with the value of point for each
    // letter
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    int points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int total1 = 0;
    int total2 = 0;

    // 1. prompt the player1 word
    string p1 = get_string("Player 1: ");
    int lengthP1 = strlen(p1);

    // 2. prompt the player2 word
    string p2 = get_string("Player 2: ");
    int lengthP2 = strlen(p2);

    // 3.1 calculate the total of point of player1
    for (int i = 0; i < lengthP1; i++)
    {
        if (p1[i] >= 'a' && p1[i] <= 'z')
        {
            for (int j = 0; j < 26; j++)
            {
                if (p1[i] == letters[j])
                {
                    total1 += points[j];
                }
            }
        }
        else
        {
            // Si c'est majuscule, je le convertit en miniscule
            p1[i] += 32;
            for (int j = 0; j < 26; j++)
            {
                if (p1[i] == letters[j])
                {
                    total1 += points[j];
                }
            }
        }
    }
    // 3.2 calculate the total of point for player2
    for (int i = 0; i < lengthP2; i++)
    {
        if (p2[i] >= 'a' && p2[i] <= 'z')
        {
            for (int j = 0; j < 26; j++)
            {
                if (p2[i] == letters[j])
                {
                    total2 += points[j];
                }
            }
        }
        else
        {
            // Si c'est majuscule, je le convertit en miniscule
            p2[i] += 32;
            for (int j = 0; j < 26; j++)
            {
                if (p2[i] == letters[j])
                {
                    total2 += points[j];
                }
            }
        }
    }


    // 4. Compare the total and display the winner !
    if (total1 > total2)
    {
        printf("Player 1 wins!\n");
    }
    else if (total2 > total1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("tie!\n");
    }
}
