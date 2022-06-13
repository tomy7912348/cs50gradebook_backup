#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
//index = 0.0588 * L - 0.296 * S - 15.8
//L means the average numbers of letters per 100 words.
//S means the average numbers of sentence per 100 words


int main(void)
{
    string text = get_string("Enter Text: ");
    float L = (float)count_letters(text) / (float)count_words(text) * 100.0;
    float S = (float)count_sentences(text) / (float)count_words(text) * 100.0;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index <= 16 && index >= 1)
    {
        printf("Grade %i\n", index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    /*
    printf("Text: %s\n", text);
    printf("%i letters\n", count_letters(text));
    printf("%i words\n", count_words(text));
    printf("%i sentences\n", count_sentences(text));
    */

}

int count_letters(string text) //count letters
{
    int letter_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letter_count++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letter_count++;
        }
    }
    return letter_count;
}

int count_words(string text) //count words
{
    //assuming that text will not start and end with space,nor have multiple spaces
    //in row, according to the instruction

    int word_count = 1; //incase of there's only one word, and 2 words makes up one space
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            word_count++;
        }
    }
    return word_count;
}

int count_sentences(string text) //count sentences
{
    //assuming every '.','!','?' as a sentence
    int sentence_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.')
        {
            sentence_count++;
        }
        else if (text[i] == '!')
        {
            sentence_count++;
        }
        else if (text[i] == '?')
        {
            sentence_count++;
        }
    }
    return sentence_count;

}