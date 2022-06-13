#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string text = get_string("Enter Text: ");
    int letter_count = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letter_count++;
        }
        else if (text[i] >='A' && text[i] <= 'Z')
        {
            letter_count++;
        }
    }
    int word_count = 1; //incase of only one word, and 2 words makes up one space
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            word_count++;
        }
    }

    printf("%i\n", letter_count);
    printf("%i\n", word_count);
}
