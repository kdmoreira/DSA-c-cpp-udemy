#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
public:
    Stack() { top = NULL; }
    void push(int x);
    int pop();
    void display();
};

// Implementing functions outside
void Stack::push(int x)
{
    Node *t = new Node();
    if (t == NULL) // That is, if t couldn't be created
    {
        cout << "Stack is full\n";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        x = top->data;
        Node *t = top; // Auxiliary pointer to delete top
        top = top->next;
        delete t; // Freeing top
    }
    return x;
}

void Stack::display()
{
    Node *p = top; // Auxiliary pointer p so that top remains at its position
    while (p != NULL) // It's p that will traverse the stack
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    stk.display();

    cout << stk.pop() << endl;

    return 0;
}
