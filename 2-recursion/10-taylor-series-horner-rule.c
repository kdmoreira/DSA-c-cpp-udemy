#include <stdio.h>
#include <stdlib.h>
/*
* Horner's Rule: considering the number of multiplications performed in a Taylor Series
* (e^x = 1 + x/1 + x^2/2! + x^3/3! +...n terms) this means 0+0+2+4+6+8... mults.,
* i.e. 2[1+2+3+4...+n], a sum of n terms, which can be: n(n+1) = O(n^2), quadratic.
* To reduce the num of mults., consider e.g.: 1 + x/1 + x^2/1*2 + x^3/1*2*3 + x^4/1*2*3*4
* i.e. 1 + x/1 (1 + x/2 + x^2/2*3 + x^3/2*3*4) -> taking the first common term
* Taking more common values: 1 + x/1 (1 + x/2 (1 + x/3 +  x^2/3*4)), and more:
* 1 + x/1 (1 + x/2 (1 + x/3 (1 + x/4))) -> reduced the num of mults by 4, O(n), linear.
*/

// This can be done using loops
double e_loop(int x, int n)
{
    double s = 1;
    for (; n > 0; n--)
    {
        // Careful with types, x & n are int, typecast or change order like this, not 1+x/n*s
        s = 1 + x * s / n;
    }
    return s;
}

// Alternative iterative version
double e_loop2(int x, int n)
{
    double s = 1;
    double num = 1;
    double den = 1;
    for (int i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

// Implementing Horner's Rule recursively
double e_rec(int x, int n)
{
    // The process is done at calling/ascending time only
    static double s = 1;
    if (n == 0)
    {
        return s;
    }
    // Typecasting to avoid int division
    s = 1 + (double)x/n * s;
    return e_rec(x, n-1);
}

int main()
{
    printf("%lf\n", e_loop(3, 10));
    printf("%lf\n", e_loop2(3, 10));
    printf("%lf\n", e_rec(3, 10));

    return 0;
}
