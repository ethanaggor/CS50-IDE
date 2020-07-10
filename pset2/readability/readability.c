#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //Get text from user
    string text = get_string("Text:");

    //Set variables for number of letters, words, and sentences
    int n = strlen(text);
    int l = 0;
    int w = 1;
    int s = 0;

    //Count the number of letters

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            l++;
        }

        //Count the number of words

        if (isspace(text[i]))
        {
            w++;
        }

        //Count the number of sentences

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++;
        }
    }

    //Average the number of letters per 100 words

    float L = (float) l / w * 100;

    //Average number of sentences per 100 words

    float S = (float) s / w * 100;

    int index = round(.0588 * L - 0.296 * S - 15.8);

    //Checks if grade level is < 1 or > 16

    if (index < 1 || index >= 16)
    {

        if (index < 1)
        {
            printf("Before Grade 1\n");
        }

        if (index >= 16)
        {
            printf("Grade 16+\n");
        }

    }
    else
    {
        printf("Grade %i\n", index);
    }
}
