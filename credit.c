#include <cs50.h>
#include <math.h>
#include <stdio.h>

int countCardNumber(long);
int checkCardBrand(long);
bool luhnAlgo(long);

int main(void)
{

    long cardnumber = 0;
    //prompt user for the credit card number
    do
    {
        cardnumber = get_long("Enter your credit card number\n");
    } while (cardnumber < 0);

    int cardLong = countCardNumber(cardnumber);
    bool validNumbers  = luhnAlgo(cardnumber);
    int cardBrand = checkCardBrand(cardnumber);

    //validates if both, number of digits and Luhn's algorithm, are correct and prints the brand of the credit card
    if ((cardLong == 13 || cardLong == 15 || cardLong == 16) && (validNumbers == true))
    {
        if (cardBrand == 1)
        {
            printf("AMEX\n");
        } else if (cardBrand == 2)
        {
            printf("MASTERCARD\n");
        } else if (cardBrand == 3)
        {
            printf("VISA\n");
        } else (printf("INVALID\n"));
    } else printf("INVALID\n");
}

//function that counts the numbers of the credit card
int countCardNumber(long number)
{
    int count = 0;
    while (number > 0)
    {
        number = number/10;
        count++;
    }
    return count;
}

//function that executes the Luhn's Algorithm and returns true or false
bool luhnAlgo(long number)
{
    //executes function that counts the number of digits of the credit card
    int cardLong = countCardNumber(number);
    int digits[cardLong];

    //creates an array with the credit card numbers (backwards)
    for (int i = 0; i < cardLong; i++)
    {
        digits[i] = number % 10;
        number = number / 10;
    }

     for (int i = 1; i < cardLong; i+=2)
    {
        digits[i] = digits[i] * 2;
    }

    int sum = 0;
    int temp;

    for (int i = 0; i < cardLong; i++)
    {
        temp = (digits[i] % 10) + (digits[i]/10 % 10);
        sum = sum + temp;
    }

    if (sum % 10 == 0)
    {
        return true;
    } else return false;
}

//function that determines which brand is the credit card
int checkCardBrand(long number)
{
    int brand = 0;
    int cardLong = countCardNumber(number);
    int digits[cardLong];

    for (int i = 0; i < cardLong; i++)
    {
        digits[i] = number % 10;
        number = number / 10;
    }

    //assign 1 for AMEX, 2 for MS, 3 for VISA and 0 for INVALID to vaiable brand and then return it
    if ((digits[cardLong-1] == 3) && (digits[cardLong-2] == 4 || digits[cardLong-2] == 7))
    {
        brand = 1;
    } else if ((digits[cardLong-1] == 5) && (digits[cardLong-2] >= 0) && (digits[cardLong-2] <= 5))
    {
        brand = 2;
    } else if (digits[cardLong-1] == 4)
    {
        brand = 3;
    } else brand = 0;

    return brand;
}
