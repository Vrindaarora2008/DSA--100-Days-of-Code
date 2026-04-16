/*Problem: Convert an infix expression to postfix notation using stack.
Input:
Single line: infix expression (operands are single characters)
Output:
Print the postfix expression
Example:
Input:
A+B*C
Output:
ABC*+
Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) 
{ 
    stack[++top] = c; 
}
char pop() 
{ 
    return stack[top--]; 
}
int prec(char c) 
{
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}
void infixToPostfix(char infix[], char postfix[]) 
{
    int i, j = 0;
    for (i = 0; infix[i]; i++) 
    {
        char c = infix[i];
        if (c >= 'a' && c <= 'z')
            postfix[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') 
        {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop(); 
        }
        else 
        {
            while (top >= 0 && prec(stack[top]) >= prec(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (top >= 0)
        postfix[j++] = pop();
    postfix[j] = '\0';
}
int main() 
{
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    gets(infix);  
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s", postfix);
    return 0;
}