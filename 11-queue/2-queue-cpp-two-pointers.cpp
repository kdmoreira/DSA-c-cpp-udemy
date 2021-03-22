#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue() {front = rear = -1; size = 10; Q = new int[size];}
    Queue(int size) {front = rear = -1; this->size = size; Q = new int[this->size];}
    void enqueue(int x);
    int dequeue();
    void display();
    bool isFull();
    bool isEmpty();
    ~Queue();
};

// Implementation

bool Queue::isEmpty()
{
    if (front == rear)
        return true;
    return false;
}

bool Queue::isFull()
{
    if (rear == size - 1)
        return true;
    return false;
}

void Queue::enqueue(int x)
{
    if (isFull())
        cout << "The queue is full!" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (isEmpty())
        cout << "The queue is empty!" << endl;
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << endl;
}

Queue::~Queue()
{
    delete [] Q;
}

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display(); // 10 20 30

    q.dequeue();
    q.enqueue(50);
    q.dequeue();

    q.display(); // 30 50

    return 0;
}
