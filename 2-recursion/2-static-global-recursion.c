#include <stdio.h>
#include <stdlib.h>

int fun1(int n)
{
    if (n > 0)
    {
        return fun1(n-1) + n; // n will be added at returning time
        // The value of n will change for every call
    }
}

int fun2(int n)
{
    // Static variables create a single copy of the variable inside code section, not stack
    static int x = 0; // Has the same effect as a global variable outside functions
    if (n > 0)
    {
        x++;
        return fun2(n-1) + x;
        // Every call will use the same copy of x, which will have the value 5
    }
}
int main()
{
    int r1 = fun1(5);
    printf("%d\n", r1); // Output will be 15

    int r2 = fun2(5);
    printf("%d\n", r2); // Output will be 25

    int r3 = fun2(5);
    printf("%d\n", r3); // Output will be 50
    /* Even though r3 is the result of fun2(5) also, since x is a static variable,
    it keeps the value 5 (from the previous call by r2) and adds up to 10 */

    return 0;
}
