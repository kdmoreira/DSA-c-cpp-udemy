#include <iostream>
using namespace std;

// Arrays are always passed by address
void fun(int A[ ], int n) // This formal parameter is actually a pointer
// Instead of A[ ], you could use *A
{
    cout << sizeof(A) / sizeof(int) << endl; // Printing the size of a pointer

    for(int i = 0; i < n; i++) // "For" loops can be used upon a pointer
    {
        cout << A[i] << endl;
    }

    A[0] = 15; // This will change the actual array since it's a pointer
}

// Function that creates an array
int * fun2(int size)
{
    int *p;
    p = (int *)malloc(size * sizeof(int)); // Possible in C and C++
    // You could also use for C++ only: p = new int[size];

    for(int i = 0; i < size; i++)
    {
        p[i] = i + 1; // Initializing each element of the array
    }

    return p;
}

int main()
{
    int A[ ] = {2,4,6,8,10};
    int n = 5;

    cout << "Size: " << sizeof(A) / sizeof(int) << endl; // Getting the size of the array

    fun(A, n);

    // "For each" loops can be used upon an array (here), but not upon a pointer (fun)
    for(int x:A)
    {
        cout << x << " ";
    }
    cout << endl;

    // Creates an array outside the main function
    int *ptr, sz = 7; // A pointer is necessary to access the array in heap memory
    ptr = fun2(sz);

    for (int i = 0; i < sz; i++)
    {
        cout << ptr[i] << endl;
    }

    return 0;
}
