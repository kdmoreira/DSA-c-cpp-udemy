#include <stdio.h>
#include <stdlib.h>

/* Since you cannot find the middle of a linked list at constant time, binary search
is not possible, you must traverse it, therefore, a linear search must be made */

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

// Iterative search
struct Node * search(int num, struct Node *p)
{
    while (p)
    {
        if (num == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

//Recursive search
struct Node * rec_search(int num, struct Node *p)
{
    if (!p)
    {
        return NULL;
    }
    if (num == p->data)
    {
        return p;
    }
    return rec_search(num, p->next);
}

// To improve linear search, you may use transposition or move to head:

/* Move to head search: considering you found the key in a node, you should have
a pointer on its previous node so that it points to the key node's subsequent node.
This means another pointer is needed (a tail pointer that will follow p pointer)*/
struct Node * mth_search(int num, struct Node *p)
{
    struct Node *prev = NULL; // Tail pointer
    while (p)
    {
        if (num == p->data)
        {
            prev->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        prev = p;
        p = p->next;
    }
    return NULL;
}

// Transposition: it switches the key's node with the previous node, an extra tail needed
struct Node * transp_search(int num, struct Node *p)
{
    struct Node *prev, *prev_prev = NULL; // Tail pointers
    while (p)
    {
        if (num == p->data)
        {
            prev_prev->next = p;
            prev->next = p->next;
            p->next = prev;
            return p;
        }
        prev_prev = prev; // prev_prev is tailing prev
        prev = p;
        p = p->next;
    }
    return NULL;
}

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

int main(void)
{
    int A[] = {8, 3, 7, 12, 9};

    create(A, 5);

    display(first);
    printf("\n");

    int temp1 = search(12, first);
    if (temp1)
        printf("Num is found: %p\n", temp1);
    else
        printf("Num not found: %p\n", temp1);

    int temp2 = search(77, first);
    if (temp2)
        printf("Num is found: %p\n", temp2);
    else
        printf("Num not found: %p\n", temp2);

    printf("%p\n", rec_search(12, first));

    printf("%p\n", transp_search(12, first));

    display(first);
    printf("\n");

    printf("%p\n", mth_search(12, first));

    display(first);
    printf("\n");

    return 0;
}
