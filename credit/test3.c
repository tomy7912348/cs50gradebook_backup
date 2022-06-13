#include <cs50.h>
#include <stdio.h>
int digits_counter(long a);
bool algorithm (long x);


int main(void)
{
    

}


bool algorithm (long x)
{
    long temp = x;  //placeholder for calculation
    int odd_num_twice = 0;
    int products_digits = 0;
    int sum1 = 0;
    int sum2 = 0;

    while (temp > 0)
    {
        odd_num_twice = ((temp /10) % 10) * 2; //start from second last digit
        while (odd_num_twice > 0) //make sure not to calculate 0
        {
            products_digits = odd_num_twice % 10; //calculate product's digits
            sum1 += products_digits;
            odd_num_twice /=10; //push to next digit before loop
        }
        temp /= 100;//push to next to digits
    }
    //reset before doing other part of sum
    products_digits = 0;
    temp = x;

    while (temp > 0)
    {
        products_digits = temp % 10; //start from last digit
        sum2 += products_digits;
        temp /= 100; //push to next two digit before loop
    }

    if (((sum1 + sum2) % 10) == 0 )
    {
        return true
    }
    else
    {
        return false
    }
}