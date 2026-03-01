#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
void ins_beg(struct node*);
void traverse();
int main()
{
    int choice;
    while(1)
    {
        printf("Enter your choices\n");
        printf("1. Insert at beginning\n");
        printf("2. Traverse\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                struct node *ptr = malloc(sizeof(struct node));
                printf("Enter data to insert at beginning\n");
                scanf("%d", &ptr->data);
                ins_beg(ptr);   
                break;
            }
            case 2:
            {
                traverse();
                break;
            }
            case 3:
            {
                exit(0);
            }
            default:
            {
                printf("Invalid choice\n");
            }
void ins_beg(struct node *ptr)
{
    ptr->next = head;
    ptr->prev = NULL;
    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        head->prev = ptr;
        ptr -> next = head;
        head = ptr;
    }
}
void traverse()
{
    struct node *ptr = head;
    if(head == NULL)
    {
        printf("No node to traverse\n");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
        }
    }
}