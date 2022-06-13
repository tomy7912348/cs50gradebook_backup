#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes; //numbers of votes the candidate has
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    // Display winner of election
    print_winner();
}


// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //selection sort the whole array (descending order)
    for (int i = 0; i < candidate_count - 1; i++)
    {
        int max_index = i;
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (candidates[j].votes > candidates[max_index].votes)
            {
                max_index = j;
            }
        }

        //swap process for both name and votes
        string temp_str = candidates[max_index].name;
        int temp = candidates[max_index].votes;
        candidates[max_index].name = candidates[i].name;
        candidates[max_index].votes = candidates[i].votes;
        candidates[i].name = temp_str;
        candidates[i].votes = temp;
    }
    printf("%s\n", candidates[0].name);

    //print out any other candidate who also win
    for (int k = 1; k < candidate_count; k++)
    {
        if (candidates[k].votes == candidates[0].votes)
        {
            printf("%s\n", candidates[k].name);
        }
    }
    return;
}