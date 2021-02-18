#include <stdio.h>
#include <stdlib.h>

// Parentheses Matching using linked list

struct Node
{
    char data;
    struct Node *next;
}*top = NULL;

char pop()
{
    struct Node *t;
    char x = -1;

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void push(char c)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
    {
        printf("Stack is full\n");
    }
    else
    {
        t->data = c;
        t->next = top;
        top = t;
    }
}

// This function, which uses the previous ones, must be declared lastly
int is_balanced(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (top == NULL)
            {
                return 0;
            }
            pop();
        }
    }
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    char *exp = "((a+b)*(c-d))";

    printf("%d\n", is_balanced(exp));

    return 0;
}
