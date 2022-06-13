#include <stdio.h>
#include "cs50.h"

int main(void)
{
    string name = get_string("What's your name?\n"); //prompt user for their name
    printf("hello, %s\n", name);
}