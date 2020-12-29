#include <stdio.h>

// Factorial (n! = 1*2*3*...*(n-1)*n) using recursion
int fac_rec(int n)
{
    if (n == 0) // 0! = 1
    {
        return 1;
    }
    return fac_rec(n - 1) * n; // Time and space complexity: O(n)
}

// This can also be done with loops
int fac_loop(int n)
{
    int fac = 1;
    for (int i = 1; i <= n; i++)
    {
        fac *= i; // Time and space complexity: O(n)
    }
    return fac;
}

int main()
{
    printf("%d\n", fac_rec(5));
    printf("%d\n", fac_loop(5));

    return 0;
}
