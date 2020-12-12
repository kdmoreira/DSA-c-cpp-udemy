#include <iostream>
using namespace std;

struct Rectangle
{
    int lenght;
    int breadth;
};

int main()
{
    struct Rectangle r0 = {10,5}; // Including "struct" is mandatory for C compilers
    Rectangle r = {10,5}; // In C++ "struct" is not mandatory
    struct Rectangle *p = &r;

    // Both can access the same value
    printf("%d\n", r.lenght);
    printf("%d\n", (*p).lenght);

    r.lenght = 20; // Use dot to assign value to normal variables
    (*p).lenght = 25; // Possible assignment for pointers
    p->lenght = 30; // Arrow is recommended, this one is possible in C++

    // Dynamically creating an object in heap using pointers
    struct Rectangle *p1;
    p1 = (struct Rectangle*)malloc(sizeof(struct Rectangle));
    /* The "struct Rectangle*" typecast is necessary
    since malloc returns a void, generic pointer */

    // Does the same, possible only in C++
    Rectangle *p2;
    p2 = new Rectangle;

    p2->lenght = 15;
    p2->breadth = 5;
    cout << p2->lenght << endl;
    cout << p2->breadth << endl;

    return 0;
}

