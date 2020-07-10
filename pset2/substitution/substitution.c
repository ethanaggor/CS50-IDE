#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[1])
{
    //Checks if key is inputted

    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    //Checks if key is 26 characters

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i <= 26; i++)
    {
        //Checks if key is alphabetic

        if (isdigit(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

        //Checks if key repeats letters

        for (int i = 0; i <= 26; i++)
        {
            for (int k = 26; k >= 0; k--)
            {

                if (argv[1][k] == argv[1][i])
                printf("Repeated letter detected\n");
                return 1;

            }
        }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: %s\n", plaintext);




}