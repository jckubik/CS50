#include <stdio.h>
#include <cs50.h>

int get_height(void);

int main(void)
{
    int height = get_height();

    for (int j = 0; j < height; j++) // Controls the number of lines, or overall height
    {
        for (int i = 0; i < height - j - 1; i++) // Prints the space portion of each line
        {
            printf(" ");
        }

        for (int l = 0; l < 2; l++)
        {
            for (int x = 0; x < j + 1; x++) // Prints the structure of the brick formation
            {
                printf("#");
            }

            if (l < 1) // Conditional to prevent from unneeded spaces
            {
                printf("  ");
            }
        }

        printf("\n");

    }
}

int get_height(void)
{
    int n;
    do
    {
        n = get_int("Height from 1-8: ");
    }
    while (n < 1 || n > 8);
    return n;
}
