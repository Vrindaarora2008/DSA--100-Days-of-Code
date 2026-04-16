/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)
Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50
Example:
Input:
5
10 4
20 3
30 2
40 1
50 0
Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50
Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        if (current->exp == exp) {
            current->coeff += coeff; // Combine like terms
            free(newNode);
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}
void printPolynomial(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->coeff > 0 && current != head) {
            printf(" + ");
        } else if (current->coeff < 0) {
            printf(" - ");
        }
        printf("%dx^%d", abs(current->coeff), current->exp);
        current = current->next;
    }
    printf("\n");
}
void freePolynomial(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}
int main() {
    struct Node* polynomial = NULL;
    int n, coeff, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertTerm(&polynomial, coeff, exp);
    }
    printf("Polynomial: ");
    printPolynomial(polynomial);
    freePolynomial(polynomial);
    return 0;
}
