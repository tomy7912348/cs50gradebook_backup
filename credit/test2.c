#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardNumber = get_long("Please, enter your card number: ");
    int sum1 = 0, num = 0, remainder = 0, sum2 = 0;
    long temp = cardNumber;

    while (temp > 0)
    {
        num = ((temp / 10) % 10) * 2; // Multiplying every other digit by 2, starting with the number’s second-to-last digit
        while (num > 0)
        {
            remainder = num % 10;
            sum1 += remainder; // Adding those products’ digits together
            num /= 10;
        }
        temp /= 100;
    }

    // So as to restore the initial values of remainder and temp for the use in next loop
    remainder = 0;
    temp = cardNumber;

    while (temp > 0)
    {
        remainder = temp % 10;
        sum2 += remainder; // Sum of the digits that weren’t multiplied by 2
        temp /= 100;
    }

    ((sum1 + sum2) % 10) == 0 ? printf("Valid\n") : printf("Invalid\n");
    return 0;
}