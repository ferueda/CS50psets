// Felipe Rueda
// CS50 2019
// pset 2

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

string changeText(string text, int key);

int main(int argc, string argv[])
{
    //validates if the number of arguments is 2 (func name and 1 argument by user) and if the key is positive
    if (argc != 2 || atoi(argv[1]) <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } else
    {
        int k = atoi(argv[1]);
        string plaintext = get_string("plain text: ");
        changeText(plaintext, k);            
    }
}

string changeText(string text, int key)
{
    //calculates the length of the initial text
    int length = strlen(text);
    char convertext[length];

    //converts each char of the string adding +k to it and normalizing for ANSCI code.
    for (int i = 0; i < length; i++)
    {
        if (isupper(text[i]))
        {
            convertext[i] = (text[i] - 65 + key) % 26 + 65;
        } else if (islower(text[i]))
        {
            convertext[i] = (text[i] - 97 + key) % 26 + 97;
        } else convertext[i] = text[i];
    }
    
    string newtext = convertext;
    printf("ciphertext: %s\n", newtext);
    return 0;
}
