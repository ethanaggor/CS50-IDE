#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[1])
{
    //Check if there is ONLY 1 command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Creates a variable for string length

    int n = strlen(argv[1]);

    //Checks if it is alphabetic, if so then returns a non-zero

    for (int i = 0; i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //Checks if it is all digits, if so then accepts key

    for (int i = 0; i < n; i++)
    {
        if (isdigit(argv[1][i]))
        {
            int integer = atoi(argv[1]);
        }
        else
        {
            return 1;
        }
    }

    //Prompt the user for a string called "plaintext"

    string plaintext[1];
    plaintext[0] = get_string("plaintext: ");

    //Creates a variable for plaintext's lengrh

    int m = strlen(plaintext[0]);

    int key = atoi(argv[1]);

    printf("ciphertext: ");

    //Adds 1 to every character

    for (int i = 0; i < m; i++)
    {
        //Converts uppercase plaintext
        if (isupper(plaintext[0][i]) || (islower(plaintext[0][i])))
        {
            if (isupper(plaintext[0][i]))
            {
                int humanplaintext = plaintext[0][i] - 65;
                int cyphertext = (humanplaintext + key) % 26;
                printf("%c", cyphertext + 65);
            }

            //Converts lowercase plaintext

            if (islower(plaintext[0][i]))
            {
                int humanplaintext = plaintext[0][i] - 97;
                int cyphertext = (humanplaintext + key) % 26;
                printf("%c", cyphertext + 97);
            }
        }

        //Prints symbols and spaces otherwise

        else
        {
            printf("%c", plaintext[0][i]);
        }


        //Creates newline after cyphering text
        if (i == m - 1)
        {
            printf("\n");

        }

    }
}