// Felipe Rueda
// CS50 2019
// pset 1

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Saving the input from the user in variable height and validating 
    int height;
    do
    {
        height = get_int("Height: \n");
    }
    while (height <= 0 || height > 8);
    
    // Iterate through rows, printing #
    for (int row = 1; row <= height; row++)
    {
        for (int space = height - row; space > 0; space--)
        {
            printf(" ");
        }
        for (int hash = 1; hash < row + 1; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
