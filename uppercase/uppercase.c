#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //  I want to put any given string to upercase !

    // 1. ask for the string
    string s = get_string("Before: ");
    // s= [O,u,m,a,r,\0] et on sait que chaque lettre est represente par son code ASCII

    int n = strlen(s);

    // 2. for each letter in the string, if it is lowercase, change it to upeercase
    printf("After: ");
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // car entre 'a'=97 et 'A'=65 il y a une diff de 32 en ascii
            //  printf("%c", s[i] - 32 );
            printf("%c", s[i] - ('a' - 'A')); // les deux fonctionnent
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    // ============= // Using  toupper() from the "ctype.h" library============ //
    for (int i = 0; i < n; i++)
    {

        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
