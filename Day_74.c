/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.
Output Format
Print the name of the winning candidate followed by the number of votes received.
Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john
Sample Output
john 4
Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Candidate 
{
    char name[100];
    int votes;
} Candidate;
int compare(const void *a, const void *b) 
{
    struct Candidate *candidateA = (struct Candidate *)a;
    struct Candidate *candidateB = (struct Candidate *)b;
    if (candidateB->votes != candidateA->votes) 
    {
        return candidateB->votes - candidateA->votes; 
    }
    return strcmp(candidateA->name, candidateB->name); 
}
int main() 
{
    int n;
    scanf("%d", &n);    
    struct Candidate candidates[100];
    int candidateCount = 0;
    for (int i = 0; i < n; i++) 
    {
        char name[100];
        scanf("%s", name);    
        int found = 0;
        for (int j = 0; j < candidateCount; j++) 
        {
            if (strcmp(candidates[j].name, name) == 0)
             {
                candidates[j].votes++;
                found = 1;
                break;
            }
        }
        if (!found) 
        {
            strcpy(candidates[candidateCount].name, name);
            candidates[candidateCount].votes = 1;
            candidateCount++;
        }
    }
    qsort(candidates, candidateCount, sizeof(struct Candidate), compare);
    printf("%s %d\n", candidates[0].name, candidates[0].votes);
    return 0;
}
