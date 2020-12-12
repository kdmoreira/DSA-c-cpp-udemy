#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    // Declaring an array
    int A[5];
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;

    // Printing values with cout statement vs printf function
    cout << sizeof(A) << endl;
    cout << A[1] << endl;
    printf("%d\n", A[2]);

    /* Initializing array with and without size,
    note that in C++ you can't redeclare an array */
    int D[5] = {2,4,6,8,10};
    int B[] = {9,8,7,6,5,4,3,2};
    int C[4] = {1,3,5};

    cout << sizeof(D) << endl;
    cout << sizeof(B) << endl;

    // Printing values outside of index range results in 0
    printf("%d\n", C[3]);
    cout << C[3] << endl;

    // Iterating through the values inside an array
    int E[5] = {1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        printf("%d\n", E[i]);
    }

    // Iterating using for each loop in C++
    for(int x:E)
    {
        cout << x << endl;
    }

    // Initializing variable-sized object
    int n;
    cout << "Enter size: ";
    cin >> n;
    int F[n] = {1,2,3};
    for(int x:F)
    {
        cout << x << endl;
    }

    // Garbage values with a for loop
    int G[n];
    for(int x:G)
    {
        cout << x << endl;
    }

    return 0;
}
