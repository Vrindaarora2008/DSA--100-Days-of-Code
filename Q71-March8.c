/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
Input:
First line: integer n (number of elements to enqueue)
Second line: n space-separated integers
Third line: integer m (number of dequeue operations)
Output:
Print queue elements from front to rear after operations, space-separated
Example:
Input:
5
10 20 30 40 50
Output:
30 40 50 10 20
Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void en_queue();
void de_queue();
void display();
int queue[MAX];
int rear = -1;
int front = -1;
int main()
{
	int choice, n;
	while(1)
    {
		printf("\nenter the choice\n");
		printf("1. enqueue\n2. dequeue\n3. display\n4. exit\n");
		scanf("%d",&choice);
		switch(choice)
        {
			case 1:
					en_queue();
					break;
			case 2:
					de_queue();
					break;
			case 3:
					display();
					break;
			case 4:
					exit(1);
			default:
					printf("Wrong choice\n");
		}
		
	}
}
void en_queue()
{
	int n;
	if((front == 0 && rear == MAX-1) || (front>0 && rear==front-1)) //(rear + 1) % MAX == front
		printf("queue overflow\n");
	else if(rear == -1){
		rear = front = 0;
		printf("enter the number ");
		scanf("%d",&n);
		
		queue[rear] = n;
		}
	else{
		rear = (rear+1) % MAX;
		printf("enter the number ");
		scanf("%d",&n);
		
		queue[rear] = n;
	}
}
void de_queue()
{
	if(rear == -1)
		printf("queue is underflow\n");
	else if(front == rear)
		rear = front = -1;
	else
		front = (front + 1) % MAX;
}
void display()
{
	int i = front;
	if(rear == -1)
		printf("queue is underflow\n");
	else
    {
			while(i != rear)
            {
				printf("%d ",queue[i]);
				i = (i+1)%MAX;
			}
			printf("%d ",queue[i]);		
	}
}
