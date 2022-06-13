#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char t, int key);


int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    // Make sure every character in argv[1] is a digit
    // Convert argv[1] from a `string` to an `int`
    // Prompt user for plaintext
    // For each character in the plaintext:
    // Rotate the character if it's a letter
    // CipherText =(plaintext+k)%26? isn't it plaintext+(k%26)?

    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if (!only_digits(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            printf("%c", rotate(plaintext[i], key));
        }
        printf("\n");
    }
}

// argv itself is a array of strings, this function input a sub-vector of argv.
// and thus, we can start the loop from i = 0.
bool only_digits(string s)
{
    int temp = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            temp++;
        }
    }
    if (temp == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char rotate(char t, int key)
{
    //covert t into int to avoid overflow during calculation
    int temp1 = (int)t;
    if (t >= 'a' && t <= 'z')
    {
        int rotated = temp1 + key % 26;
        if (rotated > 122)
        {
            rotated = rotated - 26;
        }
        return (char)rotated;
    }
    else if (t >= 'A' && t <= 'Z')
    {
        int rotated = temp1 + key % 26;
        if (rotated > 90)
        {
            rotated = rotated - 26;
        }
        return (char)rotated;
    }
    else
    {
        return t;
    }
}