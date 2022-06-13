#include <cs50.h>
#include <stdio.h>
int main(void)
{
    string card = get_string("credit card number: ");
    int i = 0;
    char odd_numbers[i];
    while (card[i] != '\0')
    {
        odd_numbers[i] = card[i];
        //printf("%c ", card[i]);
        printf("%i ", odd_numbers[i]);
        i = i + 2;
    }
    int a = 999951;
    int count = 0;
    while(a != 0)
    {
        a /= 10;
        count++;
    }
    printf("%i", count);

}
