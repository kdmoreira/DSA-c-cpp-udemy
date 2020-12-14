#include <iostream>
using namespace std;

int add(int a, int b) // Declaration of a function, with formal parameters
{
    // Definition of a function
    int c;
    c = a + b;

    return c;
}

int main()
{
    int num1 = 10, num2 = 15, sum;
    sum = add(num1, num2); // Function call, with actual parameters
    cout << "Sum is: " << sum << endl;

    return 0;
}
