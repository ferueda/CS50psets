# Felipe Rueda
# CS50 2019
# Pset 6

from cs50 import get_int

while True:
    cardnumber = get_int("Enter your card number: ")
    if cardnumber > 0:
            break

#determines credit card brand, 1 for AMEX, 2 for MS and 3 for VISA
def checkBrand(cardnumber):
    cardArray = list(map(int, str(cardnumber))) #converts int into a list

    if cardArray[0] == 3:
        if cardArray[1] == 4 or cardArray[1] == 7:
            return 1
        else: return 4
    elif cardArray[0] == 5:
        if cardArray[1] >=1 and cardArray[1] <=5:
            return 2
        else: return 4
    elif cardArray[0] == 4:
        return 3
    else: return 4

#validates credit card number using luhn's algorithm
def luhnAlgo(card_number):
    sum = 0
    card_number = str(card_number)
    num_digits = len(card_number)
    oddeven = num_digits & 1

    for count in range(0, num_digits):
        digit = int(card_number[count])

        if not (( count & 1 ) ^ oddeven ):
            digit = digit * 2
        if digit > 9:
            digit = digit - 9

        sum = sum + digit

    return ( (sum % 10) == 0 )


length = len(str(cardnumber))
luhn = luhnAlgo(cardnumber)
brand = checkBrand(cardnumber)

if luhn == True and brand != 4:
    if length == 13 or length == 15 or length == 16:
        if brand == 1:
            print("AMEX")
        elif brand == 2:
            print("MASTERCARD")
        else: print("VISA")
    else: print("INVALID")
else: print("INVALID")
