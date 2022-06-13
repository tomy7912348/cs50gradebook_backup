from math import log10
from cs50 import get_int


def main():
    card = get_int("Enter Card numbers: ")
    digits = len(str(card))

    # American Express
    if digits == 15:
        if card // 10000000000000 == 34 or card // 10000000000000 == 37:
            if algorithm(card):
                print("AMEX")
            else:
                print("INVALID")
        else:
            print("INVALID")
    # MAstercard or VISA
    elif digits == 16:
        # 16 digits VISA
        if card // 1000000000000000 == 4:
            if algorithm(card):
                print("VISA")
            else:
                print("INVALID")
        # Mastercard
        elif card // 100000000000000 == 51 or card // 100000000000000 == 52 or card // 100000000000000 == 53 or card // 100000000000000 == 54 or card // 100000000000000 == 55:
            if algorithm(card):
                print("MASTERCARD")
            else:
                print("INVALID")
        else:
            print("INVALID")
    # VISA
    elif digits == 13:
        if card // 1000000000000 == 4:
            if algorithm(card):
                print("VISA")
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")


def algorithm(card):
    # placeholder for calculation
    temp = card
    odd_num_twice = 0
    product_digits = 0
    sum1 = 0
    sum2 = 0
    while temp > 0:
        # start from second last digit
        odd_num_twice = ((temp // 10) % 10) * 2
        # make sure not to calculate 0
        while odd_num_twice > 0:
            # calculate product's digits
            product_digits = odd_num_twice % 10
            sum1 = sum1 + product_digits
            # push to next digits
            odd_num_twice //= 10
        temp //= 100
    # reset value for another part of calculation
    product_digits = 0
    temp = card

    while temp > 0:
        # start from last digit
        product_digits = temp % 10
        # push to next two digit before loop
        sum2 = sum2 + product_digits
        temp //= 100

    if ((sum1 + sum2) % 10) == 0:
        return True
    else:
        return False


if __name__ == "__main__":
    main()