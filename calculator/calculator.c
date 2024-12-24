#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Prototype
int addition(int a, int b);
int soustraction(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

//  The main
int main(void)
{

    int a = get_int("what is a ?\n");
    int b = get_int("what is b ?\n");
    char c = get_char("choose one operation to do : + , - , x , / \n");

    do
    {

        switch (c)
        {
        case '+':
            printf("a+b = %d \n", addition(a, b));
            break;
        case '-':
            printf("a-b = %d \n", soustraction(a, b));
            break;
        case 'x':
            printf("axb = %d \n", multiply(a, b));
            break;
        case '/':
            printf("a/b = %d \n", divide(a, b));
            break;
        default:
            printf("Choose the correct operator between +,-,*,/ \n ");
            break;
        }
        c = get_char("choose one operation to do : + , - , x , / \n");

    } while (c == '+' || c == '-' || c == 'x' || c == '/');
}

int addition(int a, int b)
{
    return a + b;
}

int soustraction(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    if (b == 0)
    {
        do
        {
            b = get_int("type b != 0 to continue\n ");
        } while (b != 0);
    }
    return a / b;
}
