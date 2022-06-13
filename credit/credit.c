#include <cs50.h>
#include <stdio.h>
int digits_counter(long a);
bool algorithm(long x);

int main(void)
{
    long card = get_long("Enter card numbers: "); //prompt for card
    int digits = digits_counter(card);

    if (digits == 15) //American Express
    {
        if (card / 10000000000000 == 34 || card / 10000000000000 == 37)
        {
            //algorithm
            if (algorithm(card))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digits == 16) //Mastercard or Visa
    {
        if (card / 1000000000000000 == 4) //16 digits Visa
        {
            //algorithm
            if (algorithm(card))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (card / 100000000000000 == 51 || card / 100000000000000 == 52 || card / 100000000000000 == 53 || card / 100000000000000 == 54 || card / 100000000000000 == 55) //Mastercard
        {
            //algorithm
            if (algorithm(card))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digits == 13) // Visa
    {
        if (card / 1000000000000  == 4)
        {
            //algorithm
            if (algorithm(card))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else //reject wrong digits
    {
        printf("INVALID\n");
    }

}



//calculate how many digits does card number has
int digits_counter(long a)
{
    int digi = 0;
    while (a != 0)
    {
        a /= 10;
        digi++;
    }
    return digi;
}

bool algorithm(long x)
{
    long temp = x;  //placeholder for calculation
    int odd_num_twice = 0;
    int products_digits = 0;
    int sum1 = 0;
    int sum2 = 0;

    while (temp > 0)
    {
        odd_num_twice = ((temp / 10) % 10) * 2; //start from second last digit
        while (odd_num_twice > 0) //make sure not to calculate 0
        {
            products_digits = odd_num_twice % 10; //calculate product's digits
            sum1 = sum1 + products_digits;
            odd_num_twice /= 10; //push to next digit before loop
        }
        temp /= 100;//push to next to digits
    }
    //reset before doing other part of sum
    products_digits = 0;
    temp = x;

    while (temp > 0)
    {
        products_digits = temp % 10; //start from last digit
        sum2 = sum2 + products_digits;
        temp /= 100; //push to next two digit before loop
    }

    if (((sum1 + sum2) % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}