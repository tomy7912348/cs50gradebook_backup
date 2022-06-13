#include <cs50.h>
#include <stdio.h>
char find_oddnumbers(string card);
char find_evennumbers(string card);

int main(void)
{
    string card = get_string("credit card number: ");
    int n ;
    char odd_numbers = find_oddnumbers(card);
    printf("%c", odd_numbers);



}

char find_oddnumbers(string card)
{
    int i = 0;
    char odd_numbers[i];
    while (card[i] != '\0')
    {
        odd_numbers[i] = card[i];
        i = i + 2;
    }
    return odd_numbers[i];
}

char find_evennumbers(string card)
{
    int j = 0;
    char even_numbers[j];
    while (card[j] != '\0')
    {
        even_numbers[j] = card[j];
        j = j + 1;
    }
    return even_numbers[j];
}