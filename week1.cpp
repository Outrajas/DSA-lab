#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

int space(char c)
{
    if(c == ' ' || c == '\t')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    switch(symbol)
    {
        case '^':
            return 3;
        
        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}

void print()
{
    int i=0;
    printf("The equivalent postfix expression is: ");
    while(postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

void push(char c)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow.\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop()
{
    char c;
    if(top == -1)
    {
        printf("Stack underflow.\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}

int IsEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void InfixToPostfix()
{
    int i, j = 0;
    char next, symbol;

    for(i=0; i<strlen(infix); i++)
    {
        symbol = infix[i];
        if(!space(symbol))
        {
            switch(symbol)
            {
                case '(':
                    push(symbol);
                    break;
                
                case ')':
                    while((next=pop()) != '(')
                    {
                        postfix[j++] = next;
                    }
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while(!IsEmpty() && precedence(stack[top]) >= precedence(symbol))
                    {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                    break;

                default:
                    postfix[j++] = symbol;
            }
        }
    }
    while(!IsEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main()
{
    printf("Enter the infix expression: ");
    gets(infix);

    InfixToPostfix();
    print();
    return 0;
}
