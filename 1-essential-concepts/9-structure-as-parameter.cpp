#include <iostream>
using namespace std;

struct Rectangle
{
    int lenght;
    int breadth;
};

// Call by value
void fun(struct Rectangle r1) // Both values of actual struct are copied here
{
    r1.lenght = 20; // Changes won't affect actual values
    cout << "Lenght: " << r1.lenght << endl << "Breadth: " << r1.breadth << endl;
}

// Call by address
void fun(struct Rectangle *p)
{
    p->lenght = 20; // Changes will affect actual values
    cout << "Lenght: " << p->lenght << endl << "Breadth: " << p->breadth << endl;
}

// Creating an object of type Rectangle on heap
struct Rectangle *fun() // Returning a pointer to a structure
{
    struct Rectangle *p;
    p = new Rectangle; // C++ only
    // In C, use: p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->lenght = 15;
    p->breadth = 7;
};

int main()
{
    struct Rectangle r = {10, 5};
    fun(r); // Call by value
    struct Rectangle rec = {10, 5};
    fun(&rec); // Call by address
    printf("Lenght: %d\nBreadth: %d\n", r.lenght, r.breadth);

    // Creating a struct using a function
    struct Rectangle *ptr = fun();
    cout << "Lenght: " << ptr->lenght << endl << "Breadth: " << ptr->breadth << endl;
    return 0;
}
