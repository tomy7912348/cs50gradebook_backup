from cs50 import get_string

# index = 0.0588 * L - 0.296 * S - 15.8
# L means the average numbers of letters per 100 words
# S means the average numbers of sentence per 100 words


def main():
    # user input string and convert into lower case
    text = get_string("Enter Text: ").lower()
    L = count_letters(text) / count_words(text) * 100
    S = count_sentences(text) / count_words(text) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index <= 16 and index >= 1:
        print(f"Grade {index}")
    elif index > 16:
        print(f"Grade 16+")
    elif index < 1:
        print("Before Grade 1")


def count_letters(text):
    letter_count = 0
    text_list = []
    # convert sting into a list
    text_list = list(text)
    for i in range(len(text_list)):
        if text_list[i] >= 'a' and text_list[i] <= 'z':
            letter_count = letter_count + 1
    return letter_count


def count_words(text):
    text_list_splited = text.split()
    return len(text_list_splited)


def count_sentences(text):
    comma_count = text.count('.')
    questionmark_count = text.count('?')
    exlamationmark_count = text.count('!')
    sentence_count = comma_count + questionmark_count + exlamationmark_count
    return sentence_count


if __name__ == "__main__":
    main()