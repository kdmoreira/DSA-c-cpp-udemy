#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void rec_display_tail(struct Node *p) // Time: O(n), Space: O(n)
{
    // Base condition: it could be for continuing or stopping
    if (p != NULL) // In this case, it's for continuing
    {
        printf("%d", p->data);
        rec_display_tail(p->next);
    }
}

// Now using head recursion:
void rec_display_head(struct Node *p)
{
    if (p != NULL)
    {
        rec_display_head(p->next);
        printf("%d", p->data);
    }
}

// Loop display
void display(struct Node *p)
{
    while(p != 0)
    {
        printf("%d", p->data);
        p = p->next;
    }
}

// Loop counting
int count_nodes(struct Node *p) // Time: O(n), Space: O(1)
{
    int counter = 0;
    while(p != 0)
    {
        counter++;
        p = p->next;
    }
    return counter;
}

// Recursive counting
int rec_count_nodes(struct Node *p) // Time: O(n), Space: O(n)
{
    if (p == 0)
    {
        return 0;
    }
    return rec_count_nodes(p->next) + 1;
}

// Alternative recursive counting
int alt_rec_count_nodes(struct Node *p) // Time: O(n), Space: O(n)
{
    if (p != 0)
    {
        return 1 + alt_rec_count_nodes(p->next);
    }
    return 0;
}

// Alternative recursive counting with variable
int var_alt_rec_count_nodes(struct Node *p) // Time: O(n), Space: O(n)
{
    int x = 0;
    if (p)
    {
        x = var_alt_rec_count_nodes(p->next);
        return x + 1;
    }
    return x;
}

void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int main(void)
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};

    create(A, 8);

    display(first);
    printf("\n");

    rec_display_tail(first);
    printf("\n");

    rec_display_head(first);
    printf("\n");

    printf("%d\n", count_nodes(first));

    printf("%d\n", rec_count_nodes(first));

    printf("%d\n", alt_rec_count_nodes(first));

    printf("%d\n", var_alt_rec_count_nodes(first));

    return 0;
}
