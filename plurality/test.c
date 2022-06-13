#include <cs50.h>
#include <stdio.h>
#include <string.h>


#define MAX 5

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[5];

int main(void)
{
    int candidate_count = 5;
    candidates[].name = {"A", "B", "C", "D", "E"};
    candidates[].votes = {8, 10, 9, 12, 1, 0};

    for (int i = 0; i < candidate_count - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (candidates[j].votes < candidates[min_index].votes)
            {
                min_index = j
            }
        }
        candidates[i] = candidates[min_index];
    }
    printf("%i\n%s", candidates[].votes, candidates[].name);
    return 0;


}