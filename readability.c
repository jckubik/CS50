#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

void textBreakdown(void);
void countWords(int i, int n);
void countSentences(int i);
void countLetters(int i);
int clIndex(void);

float wordCount = 1;  // Starts at one to account for the last word
float sentenceCount = 0;
float letterCount = 0;
string s;

int main(void)
{
    s = get_string("Text: ");

    textBreakdown();   // Counts the number of letters, words, and sentences in s

    int index = clIndex();

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
        return 0;
    }

}


// loop through the text looking for spaces for words and punctuation for sentences?
// strlen() gives the number of characters including spaces and punctation, need to only get letters
// Can try to use the ASCII number for letters, spaces, etc.
// A-Z == 65-90, a-z == 97-122

void textBreakdown(void)
{
    for (int i = 0, n = strlen(s); i <= n; i++)     // Loops through each char of the array
    {
        countWords(i, n);
        countSentences(i);
        countLetters(i);
    }
}

void countWords(int i, int n)
{
    if (s[i] == 32 && i != n - 1)   // If that char is a space && not the last char, then increment wordCount by 1
    {
        wordCount += 1;
    }
}

void countSentences(int i)
{
    if (s[i] == 33 || s[i] == 46 || s[i] == 63)     // 33 = '!', 46 = '.', 63 = '?'
    {
        sentenceCount += 1;
    }
}

void countLetters(int i)
{
    if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))  // If that char is a letter, the increment letterCount by 1
    {
        letterCount += 1;
    }
}

int clIndex(void)
{
    float L = (letterCount / wordCount) * 100;
    float S = (sentenceCount / wordCount) * 100;


    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}