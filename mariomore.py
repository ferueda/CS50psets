# Felipe Rueda
# CS50 2019
# Pset 06

from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

for row in range(height):
    print(" " * (height - (row + 1)), end="")
    print("#" * (row + 1), end="")
    print("  ", end="")
    print("#" * (row + 1), end="")
    print()
