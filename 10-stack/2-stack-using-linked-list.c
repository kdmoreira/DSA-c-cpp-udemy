#include <stdio.h>
#include <stdlib.h>

/* In this case, the new nodes will be added not at the "end" of the linked list,
but at the beginning, considering the operations will be O(1) and not O(n)
Stack using LL also needs a top pointer.
Conditions:
Empty: if (top == NULL)
Full: after creating a node (Node *t = new Node), if (t == NULL),i.e. not created.
Time complexity: all the operations above take constant time O(1) */

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack overflow \n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int x = -1;
    if (top == NULL)
        printf("Stack underflow \n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p;
    p = top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int peek(int pos)
{
    struct Node *p = top;
    int x = -1;
    for (int i = 0; p != NULL && i < pos - 1; i++)
    {
        p = p->next;
    }
    if (p != NULL)
        return p->data;
    else
        return -1;
}

int stack_top()
{
    if (top)
        return top->data;
    else
        return -1;
}

int is_empty()
{
    return top ? 0 : 1; // Ternary operator
}

int is_full()
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    int r = t ? 1 : 0;
    free(t);
    return r;
}

int main(void)
{
    // Using global pointer top
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    printf("%d\n", pop());

    display();

    return 0;
}
