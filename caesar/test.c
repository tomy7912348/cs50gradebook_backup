#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

    string s = argv[1];
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if(!isdigit(s[i]))
        {
            printf("f");
            i = n;
        }
        else
        {
            printf("t");
        }
    }
}