#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* In a double ended queue (also known as Deque), both front and rear pointers can be used for insertion and deletion,
but in a Queue only front is used for deletion and rear for insertion.
Therefore, a DEQueue does not strictly follow FIFO.
Variations (restricted DEQueues):
I/P Restricted (input restricted): front can't be used for insertion, but both front
and rear can be used for deletion.
O/P Restricted (output restricted): rear can't be used for deletion, but both front
and rear can be used for insertion. */

// DEQueue using array

struct DEQueue
{
    int front;
    int rear;
    int size;
    int *Q;
};

void create(struct DEQueue *deq, int size)
{
    deq->size = size;
    deq->front = deq->rear = -1;
    deq->Q = (int *)malloc(deq->size * sizeof(int));
    for (int i = 0; i < deq->size; i++)
        deq->Q[i] = 0;
}

void display(struct DEQueue deq)
{
    for (int i = deq.front + 1; i <= deq.rear; i++)
    {
        printf("%d ", deq.Q[i]);
    }
    printf("\n");
}

bool isEmpty(struct DEQueue *deq)
{
    if (deq->front == deq->rear)
        return true;
    return false;
}

bool isFull(struct DEQueue *deq)
{
    if (deq->rear == deq->size - 1)
        return true;
    return false;
}

void enqueueFront(struct DEQueue *deq, int x)
{
    if (deq->front == -1)
        printf("DEQueue Overflow\n");
    else
    {
        deq->Q[deq->front] = x;
        deq->front--;
    }
}

void enqueueRear(struct DEQueue *deq, int x)
{
    if (isFull(deq))
        printf("DEQueue Overflow\n");
    else
    {
        deq->rear++;
        deq->Q[deq->rear] = x;
    }
}

int dequeueFront(struct DEQueue *deq)
{
    int x = -1;
    if (isEmpty(deq))
        printf("DEQueue Underflow\n");
    else
    {
        x = deq->Q[deq->front + 1];
        deq->front++;
    }
    return x;
}

int dequeueRear(struct DEQueue *deq)
{
    int x = -1;
    if (isEmpty(deq))
        printf("DEQueue Underflow\n");
    else
    {
        x = deq->Q[deq->rear];
        deq->rear--;
    }
    return x;
}

int main(void)
{
    struct DEQueue d;
    create(&d, 10);

    enqueueRear(&d, 1);
    enqueueRear(&d, 2);
    enqueueRear(&d, 3);

    display(d); // 1 2 3

    printf("%d\n", dequeueFront(&d)); // 1

    display(d); // 2 3

    enqueueFront(&d, 7);
    enqueueFront(&d, 8); // DEQueue Overflow
    enqueueFront(&d, 9); // DEQueue Overflow

    display(d); // 7 2 3

    printf("%d\n", dequeueRear(&d)); // 3

    dequeueFront(&d);

    display(d); // 2
}
