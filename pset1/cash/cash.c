#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //get user input & makes sure that number is positive

    float m;

    do
    {

        m = get_float("Change owed: ");

    }
    while (m <= 0);

    //convert user input to cents

    int c = round(m * 100);

    //determine how many quarters (q), dimes (d), etc. can go into the "c" value

    int q = c / 25;

    int d = (c - (25 * q)) / 10;

    int n = (c - (25 * q) - (10 * d)) / 5;

    int p = (c - (25 * q) - (10 * d) - (5 * n)) / 1;

    int coins = q + d + n + p;

    printf("%i\n", coins);
}