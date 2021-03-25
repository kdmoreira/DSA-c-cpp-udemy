#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    struct Node *aux, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        aux = (struct Node *)malloc(sizeof(struct Node));
        aux->data = A[i];
        aux->next = NULL;
        last->next = aux;
        last = aux;
    }
}

void display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void sorted_insert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main(void)
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    sorted_insert(first, 15);
    sorted_insert(first, 45);

    display(first);

    return 0;
}
