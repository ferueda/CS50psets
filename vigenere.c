#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

string changeText(string text, string key);
int shift(char c);

int main(int argc, string argv[])
{
    //validates if the number of arguments is 2 (func name and 1 argument by user) and if the keyword contains only char
    if (argc == 2)
    {
        int klen = strlen(argv[1]); //key length
        string key = argv[1];
        for (int i = 0; i < klen; i++)
        {
            char c = key[i];
            if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
        string plaintext = get_string("plaintext: ");
        int textlen = strlen(plaintext);
        char *cipher = malloc(textlen) + 1;
        cipher = changeText(plaintext, argv[1]);
        printf("ciphertext: %s\n", cipher);
    } else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}

//function that shifts key for a numeric value
int shift(char c)
{
    char word = c;
    int key = (int)word;
    if (isupper(word))
        {
            key = (word - 65) % 26;
        } else if (islower(word))
        {
            key = (word - 97) % 26;
        } else key = word;
    return key;
}

//function that transform the text into ciphertext
char *changeText(string text, string key)
{
    int textlen = strlen(text);
    int klen = strlen(key);
    char *convertext = malloc(textlen) + 1;
    for (int i = 0, j = 0; i < textlen; i++)
    {
        int k = shift(key[j]);
        if (isupper(text[i]))
        {
            convertext[i] = (text[i] - 65 + k) % 26 + 65;
            j++;
        } else if (islower(text[i]))
        {
            convertext[i] = (text[i] - 97 + k) % 26 + 97;
            j++;
        } else convertext[i] = text[i];

        if (j == klen)
        {
            j = 0;
        }
    }
    return convertext;
}
