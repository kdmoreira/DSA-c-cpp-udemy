#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
    int data;
    struct Node *next;
}*firstA = NULL, *firstB = NULL;

// Iterative sum
int sum(struct Node *p) // O(n)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

// Recursive sum
int rec_sum(struct Node *p) // O(n)
{
    if (p == NULL)
    {
        return 0;
    }
    return rec_sum(p->next) + p->data;
}

// Iterative maximum element
int max(struct Node *p)
{
    int MIN_INT = -32768; // Smallest number in a 2-byte integer
    int max = MIN_INT;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

// Recursive maximum element
int rec_max(struct Node *p)
{
    int x = 0;
    int max = INT32_MIN; // From <stdint.h> macro
    if (!p)
    {
        return max;
    }
    x = rec_max(p->next);
    if (x > p->data)
    {
        return x;
    }
    return p->data;

}

// Alternative recursive max (with ternary operator)
int alt_rec_max(struct Node *p)
{
    int x = 0;
    int max = INT32_MIN;
    if (!p)
    {
        return max;
    }
    x = alt_rec_max(p->next);
    return x > p->data ? x : p->data; // Ternary operator
    // If x > p->data, return x, otherwise, return p->data
}

int min(struct Node *p)
{
    int min = INT32_MAX;
    while (p)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

// Recursive minimum element
int rec_min(struct Node *p)
{
    int x = 0;
    int min = INT32_MAX;
    if (!p)
    {
        return min;
    }
    x = rec_min(p->next);
    if (x < p->data)
    {
        return x;
    }
    return p->data;
}

void createA(int A[], int n)
{
    struct Node *t, *last;
    firstA = (struct Node *)malloc(sizeof(struct Node));
    firstA->data = A[0];
    firstA->next = NULL;
    last = firstA;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void createB(int A[], int n)
{
    struct Node *t2, *last2;
    firstB = (struct Node *)malloc(sizeof(struct Node));
    firstB->data = A[0];
    firstB->next = NULL;
    last2 = firstB;

    for (int i = 1; i < n; i++)
    {
        t2 = (struct Node *)malloc(sizeof(struct Node));
        t2->data = A[i];
        t2->next = NULL;
        last2->next = t2;
        last2 = t2;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
}

int main(void)
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    int B[] = {2, 10, 8, 3, 14, 1, 7, 5};

    createA(A, 10);

    createB(B, 8);

    display(firstA);
    printf("\n");

    display(firstB);
    printf("\n");

    printf("%d\n", sum(firstA));

    printf("%d\n", rec_sum(firstA));

    printf("%d\n", max(firstB));

    printf("%d\n", rec_max(firstB));

    printf("%d\n", alt_rec_max(firstB));

    printf("%d\n", min(firstB));

    printf("%d\n", rec_min(firstB));

    return 0;
}
