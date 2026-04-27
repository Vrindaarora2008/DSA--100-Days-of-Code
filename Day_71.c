/*Problem Statement
Implement a hash table using quadratic probing with formula:
h(k, i) = (h(k) + i*i) % m
Input Format
Same as previous.
Output Format
Result of SEARCH operations.
Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15
Sample Output
FOUND
NOT FOUND
Explanation
Collisions resolved using i² jumps.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int hashTable[MAX];
int hashFunction(int key, int i, int m) 
{
    return (key + i * i) % m;
}
void insert(int key, int m) 
{
    int i = 0;
    int index;
    while (i < m) {
        index = hashFunction(key, i, m);
        if (hashTable[index] == -1) {
            hashTable[index] = key;
            return;
        }
        i++;
    }
    printf("Hash table is full. Cannot insert key: %d\n", key);
}
int search(int key, int m) {
    int i = 0;
    int index;
    while (i < m) {
        index = hashFunction(key, i, m);
        if (hashTable[index] == -1) {
            return 0;
        }
        if (hashTable[index] == key) {
            return 1;
        }
        i++;
    }
    return 0; 
}
int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    for (int i = 0; i < MAX; i++) {
        hashTable[i] = -1; 
    }
    for (int i = 0; i < n; i++) {
        char operation[10];
        int key;
        scanf("%s %d", operation, &key);
        if (strcmp(operation, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(operation, "SEARCH") == 0) {
            if (search(key, m)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }
    return 0;
}
