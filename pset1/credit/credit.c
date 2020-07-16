#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get user input
    long ccNumber;
    ccNumber = get_long("Number: ");

    //Multiply every other digit by 2 starting with the second-to-last digit

    ccNumber %= 10;

    printf("%ld\n", ccNumber);

    //Add product's digits together

    //Add sum to the sum of digits that weren't counted

    //If the last digit was zero, number is valid

}