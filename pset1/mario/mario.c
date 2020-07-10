#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int n;


    // What is the height of our stairs?
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //As long as i is less than n, continue to print

    for (int i = 0; i < n; i++)
    {

        //prints space on left stairs

        for (int j = n - 1; j > i; j--)
        {
            printf(" ");
        }

        //prints right-aligned stairs

        for (int j = -1; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}