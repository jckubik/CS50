#include <stdio.h>
#include <cs50.h>

    int qualifyingStartingDigits(void);
    int conditionals(int begNums);
    int x = 0;
    int y = 0;
    int z = 0;
    int n;
    int i;
    long ccNumber;
    long ogCCNumber;


int main(void)
{
    ccNumber = get_long("Enter your credit card number: ");
    ogCCNumber = ccNumber;

    for (i = 0; ccNumber != 0; i++)
    {
        if (i % 2 == 0 || i == 0)   // Runs the code every-other number
        {
            n = ((ccNumber / 10) % 10) * 2;     // Gets the second to last degit and multiplies by 2

            x += (n % 10) + (n / 10);    // Adds the degits of the multiplied number together and adds to total

            y += ccNumber % 10;     // Add together the last degits together
        }

        ccNumber /= 10;

    }

    z += x + y;
    int begNums = qualifyingStartingDigits();

    conditionals(begNums);
}




int qualifyingStartingDigits(void) // Selects the first two digits of the cc number
{
    for (int h = i - 2; h > 0; h--)
    {
       ogCCNumber /= 10;
    }
    return ogCCNumber;
}

int conditionals(int begNums)   // Conditions to decide which type of card it is, or if invalid
{
    if (z % 10 == 0 && i <= 16 && i >= 13)
    {
        int firstDigit = begNums / 10;
        int secondDigit = begNums % 10;

        if (i == 16)
        {
            if (firstDigit == 4)
            {
                return printf("VISA\n");
            }

            if (firstDigit == 5 && (secondDigit == 1 || secondDigit == 2 || secondDigit == 3 || secondDigit == 4 || secondDigit == 5))
            {
                return printf("MASTERCARD\n");
            }
        }

        if (i == 13 && firstDigit == 4)
        {
            return printf("VISA\n");
        }

        if (i == 15 && firstDigit == 3 && (secondDigit == 4 || secondDigit == 7))
        {
            return printf("AMEX\n");
        }
        else
        {
            return printf("INVALID\n");
        }
    }
    else
    {
        return printf("INVALID\n");
    }
}