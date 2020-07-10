#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
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
    //Checks if more than one candidate is given
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] == ' ')
        {
            return false;
        }
    }

    //Checks if name given matches one of the names of candidates in the election and adds vote to that candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }

    return false;

}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //Array of largest # of votes with a possibility of a nine-way tie
    int largest[10];
    largest[0] = 0;

    //Finds the largest # of votes

    for (int i = 0; i < candidate_count; i++)
    {
        if (largest[0] < candidates[i].votes)
        {
            largest[0] = candidates[i].votes;
        }

        //Duplicates largest value to corresponding candidate if there are multiple of the same value

        if (largest[0] == candidates[i + 1].votes)
        {
            largest[i + 1] = largest[0];
        }

    }

    //Prints winner, if there are multiple, it will print multiple winners
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == largest[0] || largest[i + 1] == largest[0])
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}