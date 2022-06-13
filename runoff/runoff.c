#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i; //i as the index number of that candidate
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++) //each voter
    {
        for (int j = 0; j < candidate_count; j++) //every candidate
        {
            if (candidates[j].eliminated == false) //not eliminated
            {
                for (int k = 0; k < candidate_count; k++) //check each line of preference
                {
                    if (preferences[i][k] == j)
                    {
                        candidates[j].votes++;
                    }
                    else if (candidates[preferences[i][k]].eliminated == true) //if this line's preference is eliminated
                    {
                        if (preferences[i][k + 1] == j)
                        {
                            candidates[j].votes++;
                            break;
                        }
                    }
                    else if (candidates[preferences[i][k]].eliminated == false)
                    {
                        break;
                    }
                }
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    // make a temp array for this function, leave the original structure alone
    int total_votes = 0;
    for (int i = 0; i < candidate_count; i++) //calculate total votes number
    {
        total_votes = total_votes + candidates[i].votes;
    }

    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes > (total_votes / 2))
        {
            printf("%s\n", candidates[j].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int min = 0;
    // make a temp array for this function, leave the original structure alone
    candidate temp_candidates[MAX_CANDIDATES];
    for (int l = 0; l < candidate_count; l++)
    {
        if (candidates[l].eliminated == false)
        {
            temp_candidates[l].name = candidates[l].name;
            temp_candidates[l].votes = candidates[l].votes;
        }
    }
    //selection sort the whole array (descending order)
    for (int i = 0; i < candidate_count - 1; i++)
    {
        int max_index = i;
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (temp_candidates[j].votes > temp_candidates[i].votes)
            {
                max_index = j;
            }
        }
        //swap
        string temp_str = temp_candidates[max_index].name;
        int temp = temp_candidates[max_index].votes;
        temp_candidates[max_index].name = temp_candidates[i].name;
        temp_candidates[max_index].votes = temp_candidates[i].votes;
        temp_candidates[i].name = temp_str;
        temp_candidates[i].votes = temp;
    }
    min = temp_candidates[candidate_count - 1].votes;
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    int temp_counter = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if ((candidates[i].votes != min) && (candidates[i].eliminated == false))
        {
            temp_counter++;
        }
    }
    if (temp_counter == 0)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}