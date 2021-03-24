#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Drawbacks of Queue using Arrays:
1. Cannot use spaces of deleted elements;
2. Every location can be used only once;
3. The queue could be considered empty and full at the same time;

Solutions:
1. Reset pointers by reinitializing them to -1 when front == rear, but it doesn't guarantee
the use of free spaces if they never come to be equal;
2. Circular queue, a better solution: front and rear will start from 0 (not -1 as done previously)
and with an insertion the element should be placed to index 1, index 0 should be left empty.
When rear == size - 1, if there have been dequeued elements, check if 0 is empty (but the front
pointer mustn't be pointing at 0, since where it points to must always be empty) and if so, enqueue
the new element in the "beginning" of the array, thus the "circular". This is done using a modulo
operation: rear = (rear + 1) % size

*/

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->Q = (int *)malloc(q->size * sizeof(int));
    q->front = q->rear = 0;
}

bool isFull(struct Queue q)
{
    if ((q.rear + 1) % q.size == q.front)
        return true;
    return false;
}

bool isEmpty(struct Queue q)
{
    if (q.rear == q.front)
        return true;
    return false;
}

void enqueue(struct Queue *q, int x)
{
    if (isFull(*q))
        printf("Queue is full!\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (isEmpty(*q))
        printf("Queue is empty!\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i+1) % q.size;
    } while (i != (q.rear + 1) % q.size);

    printf("\n");
}

int main(void)
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    display(q);

    printf("%d ",dequeue(&q));

    return 0;
}
