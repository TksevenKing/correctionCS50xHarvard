#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // 1. Prompt the user the "change due"
    int money;
    do
    {
        money = get_int("Change owed: ");
    } while (money < 0);

    // 2. count the number of coins to return
    int pieces[4] = {25, 10, 5, 1};

    int i = 0, nbrPiece = 0, n = 4;

    while (i < n)
    {
        if (money >= pieces[i])
        {

            money -= pieces[i];
            nbrPiece++;
        }
        else
        {
            i++;
        }
    }
    printf("%d\n", nbrPiece);
}
