/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the circular linked list elements starting from head, space-separated
Example:
Input:
5
10 20 30 40 50
Output:
10 20 30 40 50
Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insbeg(struct node*ptr)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d",&temp->data);
    temp->next=ptr;
    ptr=temp;
}
void display(struct node*ptr)
{
    struct node*temp=ptr;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != ptr);
}
int main() {
    struct Node* head = NULL;
    int n, i, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Point to itself to make it circular
        } else {
            struct Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode; // Link the last node to the new node
            newNode->next = head; // Point the new node to head
        }
    }
    printf("Circular Linked List: ");
    display(head);
    return 0;
}