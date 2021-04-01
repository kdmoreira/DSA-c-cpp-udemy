#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    // If a new node is not created, heap memory is full
    if (t == NULL)
    {
        printf("Queue is full!");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    if (front == NULL)
    {
        printf("Queue is empty!");
    }
    else
    {
        struct Node *temp;
        temp = front;
        x = front->data;
        front = front->next;
        free(temp);
    }
    return x;
}

void display()
{
    struct Node *p;
    p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}
