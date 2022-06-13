#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int n; //variable for size
    do
    {
        n = get_int("Size(1-8): "); //prompt user for size
    }
    while (n > 8 || n < 1); //keeps prompting user when n is not 1-8

    for (int i = 0; i < n; i++) //for each row
    {
        for (int j = 1; j < n - i; j++) //blanks on left side for each row
        {
            printf(" ");
        }

        for (int k = 0; k < i + 1; k++) //hashes on left side
        {

            printf("#");
        }

        printf("  "); //two blanks in the middle

        for (int l = 0; l < i + 1; l++) //hashes on right side
        {
            printf("#");
        }

        printf("\n"); //move to next row

    }
    return 0;
}


