#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string entrada =  argv[1];
    if (strlen(entrada) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, n = strlen(entrada); i < n; i++)
    {
        if (! isalpha(entrada[i]))
        {
            printf("Only alphabetic characters allowed.");
            return 1;
        }

        if ((int)entrada[i] > 64 && (int)entrada[i] < 91)
        {
            entrada[i] = ((int)entrada[i] + 32);
        }

        for (int b = 0, o = strlen(entrada); b < o; b++)
        {
            if (b != i)
            {
                if (entrada[b] == entrada[i])
                {
                    printf("Cannot repeat letters.\n");
                    return 1;
                }
            }
        }


    }

    string plaintext = get_string("plaintext: ");

    /* Render ciphered text, by looking at the positions at key string */

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if ((int)plaintext[i] > 64 && (int)plaintext[i] < 91)
        {
            int alfaindex = (int)plaintext[i] - 64 - 1;
            plaintext[i] = entrada[alfaindex];
            plaintext[i] = ((int)plaintext[i] - 32);
        }

        if ((int)plaintext[i] > 96 && (int)plaintext[i] < 123)
        {
            int alfaindex = (int)plaintext[i] - 96 - 1;
            plaintext[i] = entrada[alfaindex];
        }
    }
    printf("ciphertext: %s\n", plaintext);

}

