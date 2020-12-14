#include <iostream>
using namespace std;

// This is an example of passing by value
int increase_a(int a) // Changes in formal parameters won't change actual parameters
{
    a++;
    cout << "Now num1 is " << a << endl;

}

// This is an example of passing by address
int increase_b(int *b) // Changes here will affect actual parameters
{
    (*b)++; // Use () since ++operator precedence is higher than dereference
    cout << "Now num2 is " << *b << endl;
    *b += 1; // Also possible
    cout << "And now it's " << *b << endl;
    // Don't use *b++ since it increments the pointer, not the dereferenced value
}

int swap(int *x, int *y) // Another example of passing by address
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// This is an example of passing by reference, possible in C++
int swap(int &x, int &y) // This creates "nicknames" for the actual variables
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    // Passing by value
    int num1 = 10;
    increase_a(num1);
    cout << "Final num1 value: " << num1 << endl; // Doesn't change

    // Passing by address
    int num2 = 10;
    increase_b(&num2);
    cout << "Final num2 value: " << num2 << endl; // Changed

    int num3 = 10, num4 = 15;
    cout << "num3 is " << num3 << " and num4 is " << num4 << endl;
    swap(&num3, &num4);
    cout << "Now num3 is " << num3 << " and num4 is " << num4 <<endl; // Changed

    // Passing by reference
    int num5 = 10, num6 = 15;
    cout << "num5 is " << num5 << " and num6 is " << num6 << endl;
    swap(num5, num6);
    cout << "Now num5 is " << num5 << " and num6 is " << num6 <<endl; // Changed
    /* Depending on the compiler, when a function is called by reference it may
    become an inline function or not (they'll be treated as pointers) */

    return 0;
}
