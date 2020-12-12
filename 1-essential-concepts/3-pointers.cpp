#include <iostream>
#include <stdlib.h>
using namespace std;

  struct Rectangle
{
    int lenght;
    int breadth;
};

int main()
{
    int a = 10;
    int *p; // Declaration of a pointer
    p = &a; // Storing the address of a

    cout << p << endl;
    printf("Address of 'a': %d\n", p);
    printf("Same: %d\n", &a);

    cout << *p << endl;
    printf("Content of 'a': %d\n", *p);

    // Pointers with arrays
    int A[5] = {1,2,3,4,5};
    int *q;
    int *r;
    q = A; // This is valid
    cout << q << endl;
    r = &A[0]; // This is also valid
    cout << r << endl;

    // Iterating through an array using pointers
    for(int i=0;i<5;i++)
    {
        cout << q[i] << endl;
    }

    // Creating an array of 5 int inside heap memory
    int *s;
    s = (int *)malloc(5*sizeof(int)); // This is the C way of doing it
    s[0] = 1; s[1] = 2; // Initializing a few values
    for(int i=0;i<5;i++)
    {
        cout << s[i] << endl;
    }
    free(s); // Deallocating the memory the C way
    cout << "Now inside s[0]: " << s[0] << endl;

    int *t;
    t = new int[5]; // This is the C++ way of doing it
    t[0] = 10; // Initializing a value
    for(int i=0;i<5;i++)
    {
        cout << t[i] << endl;
    }
    delete [] t; // Deallocating the memory the C++ way
    cout << "Now inside t[0]: " << t[0] << endl;

    /* As for free and delete, note that when the program ends, the heap memory
    will be automatically freed even if you don't de-allocate it */

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    // The size of the pointer is independent of the data type
    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;
    cout << sizeof(p5) << endl;

    return 0;
}
