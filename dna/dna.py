import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequense.txt")
        exit(1)

    # TODO: Read database file into a variable
    # this list contain STRs in question
    STRs = []
    data = []
    data_filename = sys.argv[1]
    with open(data_filename, mode="r") as data_file:
        data_reader = csv.DictReader(data_file)
        # Record first row into STRs except 'name'
        STRs = data_reader.fieldnames[1:]
        # read each set of dictionary into a list
        for name in data_reader:
            data.append(name)
    # TODO: Read DNA sequence file into a variable
    sequense_filename = sys.argv[2]
    with open(sequense_filename, mode="r") as sequense_file:
        sequense_reader = sequense_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    STRs_count = {}
    for i in STRs:
        STRs_count[i] = longest_match(sequense_reader, i)
    # TODO: Check database for matching profiles
    # each person
    for name in data:
        ismatch = 0
        # each STR
        for j in STRs:
            if STRs_count[j] == int(name[j]):
                ismatch += 1
            continue
        if ismatch == len(STRs):
            print(name['name'])
            exit(0)
    print("No match")
    exit(0)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
