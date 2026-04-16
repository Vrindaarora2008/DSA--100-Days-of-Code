/*Problem: Deque (Double-Ended Queue)
A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
clear, erase, resize, assign, reverse: O(n)
sort: O(n log n)
Input:
Sequence of deque operations with values (if applicable)
Output:
Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int deque[MAX_SIZE];
int front = -1;
int rear = -1;
void push_front(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }
    deque[front] = value;
}
void push_back(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
}
void pop_front() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}
void pop_back() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }
}
int front_element() {
    if (front == -1) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[front];
}
int back_element() {
    if (rear == -1) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[rear];
}
int is_empty() {
    return front == -1;
}
int size() {
    if (front == -1) {
        return 0;
    }
    if (rear >= front) {
        return rear - front + 1;
    }
    return MAX_SIZE - front + rear + 1;
}
void clear() {
    front = rear = -1;
}
void print_deque() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}
int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);
    printf("Deque after insertions: ");
    print_deque();
    printf("Front element: %d\n", front_element());
    printf("Back element: %d\n", back_element());
    printf("Size of deque: %d\n", size());
    pop_front();
    printf("Deque after popping front: ");
    print_deque();
    pop_back();
    printf("Deque after popping back: ");
    print_deque();
    clear();
    printf("Deque after clearing: ");
    print_deque();
    return 0;
}
