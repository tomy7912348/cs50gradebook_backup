from cs50 import get_int


def main():
    size = 0
    # keeps promting user for size 1-8
    while size > 8 or size < 1:
        size = get_int("Size(1-8): ")
    # for each row
    for i in range(size):
        # blanks on left side
        for j in range(1, size - i):
            print(" ", end="")
        # hashes on left side
        for k in range(i + 1):
            print("#", end="")
        # two blanks in middle
        print("  ", end="")
        # hashes on right side
        for l in range(i + 1):
            print("#", end="")
        print("")


if __name__ == "__main__":
    main()