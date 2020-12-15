
// User must use command line to input 26 character key (a-z)
    // prompt again for a key if not 26 letters
    // prompt again if not a-zA-Z
// program shouldn't substitute punctuation, commas, etc.
// Casing matters, if plain text input in caps, substitute text should be in caps, etc.
// Case doesn't matter in the key though, should accept any variation of letters

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int commandLineVerification(string s);
int cmpfunc (const void * a, const void * b);
void cipherGenerator(char copy[], string plainText);
int toascii(int c);

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2) // Checks if at least && only 1 key input
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string s = argv[1];
        char copy[26];
        strcpy(copy, argv[1]);
        printf("argc: %i, s: %s\n", argc, s);

        int functionReturn = commandLineVerification(s);
        if (functionReturn == 1)
        {
            return functionReturn;
        }
        printf("function return: %d\n", functionReturn);

        string plainText = get_string("plaintext: ");

        cipherGenerator(copy, plainText);

        return functionReturn;
    }
}




int commandLineVerification(string s)
{
    string key = s;
    int returnValue = 0;
    int sLength = strlen(key);
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    if (sLength < 26 || sLength > 26) // Throws error if key input was != 26
    {
        printf("Key must contain 26 characters.\n");
        return returnValue = 1;
    }

    for (int i = 0; i < sLength; i++)
    {
        key[i] = tolower(key[i]); // Converts each char in key to lowercase for sorting

        if (!isalpha(key[i])) // Loops through each character of key to check for non-letters
        {
            printf("Key must only contain alphabetic characters.\n");
            return returnValue = 1;
        }
    }

    qsort(&key[0], sLength, sizeof(key[0]), cmpfunc); // Sorts the key in alphabetical order
    printf("sorted: %s\n", key);

    if (strcmp(key, alphabet) != 0) // If sorted-key != alphabet, assume repeated letter
    {
        printf("Key must contain each letter once.\n");
        return returnValue = 1;
    }


    if(sLength == 26 && strcmp(key, alphabet) == 0)
    {
        printf("Length is 26\n");
        return returnValue = 0;
    }

    return returnValue;
}


int cmpfunc (const void * a, const void * b)
{
   return ( *(char*)a - *(char*)b );
}

// a-z:97-122, A-Z:65-90, abcdefghijklmnopqrstuvwxyz


void cipherGenerator(char copy[], string plainText)
{
    int pLength = strlen(plainText);
    int copyLength = strlen(copy);
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int n = strlen(alphabet);


    for (int i = 0; i < copyLength; i++) // converts the copy to lowercase, only deal with a-z:97-122
    {
        copy[i] = tolower(copy[i]);

    }

    printf("ciphertext: ");

    for (int x = 0; x < pLength; x++)
    {
        for (int j = 0; j < n; j++)
        {
            if (plainText[x] == alphabet[j] || plainText[x] == alphabet[j] - 32)
            {
                if (isupper(plainText[x]))
                {
                    printf("%c", toupper(copy[j]));
                }
                else
                {
                    printf("%c", copy[j]);
                }
            }
        }
            if ((plainText[x] < 97 || plainText[x] > 122) && (plainText[x] < 65 || plainText[x] > 90))
            {
                printf("%c", plainText[x]);
            }
    }

    printf("\n");
}