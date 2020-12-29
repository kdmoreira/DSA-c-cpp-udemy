#include <stdio.h>

/* Solving exponential with recursion, if follows the logic:
(m)^n, that is, m*m*m*... for (n-1) times * n times */
int pow_A(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return pow_A(m, n-1) * m;
    // This type of function takes n+1 calls
}
/*
There is a way to reformulate this function so that it takes less calls,
* considering, i.e.: 2^4 = (2^2)^2 | 2^5 = 2*(2^2)^2, therefore:
* if n is even: m^n = (m*m)^n/2
* if n is odd: m^n = m*(m*m)^(n-1)/2
*/

// Faster since it takes fewer multiplications to find the result
int pow_B(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return pow_B(m * m, n/2);
    }
    return m * pow_B(m * m, (n-1)/2);
}

// Using a for loop
int pow_loop(m, n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= m;
    }
    return result;
}

int main()
{
    // Taking 2^9 as an example, pow_A would take 9 multiplications to be done
    int r1 = pow_A(2, 9);
    printf("%d\n", r1);

    // pow_B would take 6 multiplications to be done
    int r2 = pow_B(2, 9);
    printf("%d\n", r2);

    // pow_loop takes 9 multiplications, but is less space consuming
    int r3 = pow_loop(2, 9);
    printf("%d\n", r3);

    return 0;
}
