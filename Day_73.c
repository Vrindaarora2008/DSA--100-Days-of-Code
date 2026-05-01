/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.
Input Format
A single string s.
Output Format
Print the first non-repeating character or '$' if none exists.
Sample Input
geeksforgeeks
Sample Output
f
Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.*/
#include<stdio.h>
#include<stdlib.h>
char firstNonRepeatingCharacter(char *s) {
    int count[26] = {0}; 
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }
    for (i = 0; s[i] != '\0'; i++) 
    {
        if (count[s[i] - 'a'] == 1) 
        {
            return s[i]; 
        }
    }
    return '$'; 
}