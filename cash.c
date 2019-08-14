#include <stdio.h>
#include <cs50.h>
#include <math.h>

void pennies(int newOwed);

int main(void) 
    {
    float owed;
    //prompt user for the amount of change
    do 
    {
        owed = get_float("How much is owed?\n");
        printf("Change owed is $%.2f\n", owed);
    } while (owed < 0);
    owed = round(owed*100);
    int newOwed = (int)owed;
    pennies(newOwed);
}

//coins counter function
void pennies(int newOwed)
{
    int coinCounter = 0;
    while (newOwed > 0)
    {   
        if (newOwed >= 25)
        {
            do
            {
                newOwed = newOwed - 25;
                coinCounter++;
            } while (newOwed >= 25);
        } else if (newOwed >= 10)
        {
            do
            {
                newOwed = newOwed - 10;
                coinCounter++;
            } while (newOwed >= 10);
        } else if (newOwed >= 5)
        {
            do
            {
                newOwed = newOwed - 5;
                coinCounter++;
            } while (newOwed >= 5);
        } else
        {
               do
            {
                newOwed = newOwed - 1;
                coinCounter++;
            } while (newOwed >= 1);
        }
    }
    printf("$%i left \n", newOwed);    
    printf("%i coins \n", coinCounter);
}