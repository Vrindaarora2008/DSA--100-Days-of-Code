/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
Input:
Postfix expression with operands and operators
Output:
Print the integer result
Example:
Input:
2 3 1 * + 9 -
Output:
-4
Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }
int main() {
    char exp[MAX];
    int i, a, b;
    printf("Enter postfix expression: ");
    fgets(exp, MAX, stdin);
    for (i = 0; exp[i]; i++) 
    {
        char c = exp[i];
        if (isdigit(c))
            push(c - '0');
        else if (c == '+' || c == '-' || c == '*' || c == '/') 
        {
            b = pop();
            a = pop();
            if (c == '+') 
            {
                push(a + b);
            }
            else if (c == '-') 
            {
                push(a - b);
            }
            else if (c == '*') 
            {
                push(a * b);
            }
            else 
            {
                push(a / b);
            }
        }
    }
    printf("Result: %d", pop());
    return 0;
}