#include <stdio.h>
#include <stdlib.h>

/* Queues follow the FIFO (first in, first out) rule.
Using an array with single pointer (rear), enqueue takes O(1) while dequeue takes O(n),
since all the elements must be shifted one place near the beginning every
time an element is taken out */

// Queue using a single pointer upon an array

struct Queue
{
    int size;
    int rear;
    int *q;
};

void create(struct Queue *q)
{
    q->q = (int *)malloc(q->size * sizeof(int));
    q->rear = -1;
}

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->q[q->rear] = x;
    }
}

void dequeue(struct Queue *q)
{
    if (q->rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        // Shifting elements
        for (int i = 0; i < q->rear; i++)
        {
            q->q[i] = q->q[i + 1];
        }
        q->rear--;
    }
}

void display(struct Queue q)
{
    for (int i = 0; i < q.rear + 1; i++)
    {
        printf("%d ", q.q[i]);
    }
    printf("\n");
}

/* Queue using two pointers upon an array eliminates the drawback of dequeue
taking O(n) time, now both enqueue and dequeue take constant time O(1) */

struct Queue_2pt
{
    int size;
    int rear;
    int front;
    int *q;
};

void create2(struct Queue_2pt *q)
{
    q->q = (int *)malloc(q->size * sizeof(int));
    q->rear = q->front = -1;
}

void enqueue2(struct Queue_2pt *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->q[q->rear] = x;
    }
}

int dequeue2(struct Queue_2pt *q)
{
    int x = -1;
    if (q->rear == q->front)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front++;
        x = q->q[q->front];
    }
    return x;
}

void display2(struct Queue_2pt q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.q[i]);
    }
    printf("\n");
}

int main(void)
{
    // Testing queue 1 pointer
    struct Queue queue;
    printf("Enter size: "); // Suppose size is 3
    scanf("%d", &queue.size);
    create(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40); // Queue is full
    display(queue); // 10 20 30
    dequeue(&queue);
    display(queue); // 20 30
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue); // Queue is empty

    // Testing queue 2 pointers
    struct Queue_2pt queue2;
    printf("Enter size: ");
    scanf("%d", &queue2.size);
    create2(&queue2);
    enqueue2(&queue2, 10);
    enqueue2(&queue2, 20);
    enqueue2(&queue2, 30);
    enqueue2(&queue2, 40); // Queue is full
    display2(queue2); // 10 20 30
    dequeue2(&queue2);
    display2(queue2); // 20 30
    dequeue2(&queue2);
    dequeue2(&queue2);
    dequeue2(&queue2); // Queue is empty

    return 0;
}
