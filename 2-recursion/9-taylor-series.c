#include <stdio.h>

/*
* A natural exponential function can be defined by the Taylor Series:
* e^x = 1 + x/1 + x^2/2! + x^3/3! +...n terms.
* It performs three operations: sum(n-1)+n, fact(n-1)*n, pow(x, n-1)*x
* The function can return only one value, so static variables must be used.
*/

// This approach takes more time
double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }
    r = e(x, n-1);
    // Below, performed at returning time
    p *= x;
    f *= n;

    return r + p/f;
}

int main()
{
    // The higher n is, more precise is the function
    double r = e(3, 10);
    printf("%lf\n", r);

    return 0;
}
