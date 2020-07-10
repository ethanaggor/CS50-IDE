#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int n;

    //asks for height

    do
    {

        n = get_int("Height:");

    }
    while (n < 1 || n > 8);


    for (int j = 1; j <= n; j++)
    {

        //prints left side of pyramid w/ dpaces

        for (int k = n - 1; k >= j; k--)
        {
            printf(" ");
        }

        for (int i = 1; i <= j; i++)
        {
            printf("#");
        }

        //puts spaces between two slopes

        printf(" ");
        printf(" ");

        //prints the last slope

        for (int l = 1; l <= j; l++)
        {
            printf("#");
        }

        printf("\n");
    }

}