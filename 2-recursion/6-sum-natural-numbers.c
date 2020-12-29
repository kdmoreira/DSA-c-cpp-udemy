#include <stdio.h>

// These functions sum up natural numbers up to n
int sum_recursion(int n)
{
    if (n == 0)
    {
        return 0; // Base case
    }
    return sum_recursion(n - 1) + n; // Time and space complexity: O(n)
    /* Many activation records will be created (n + 1) in the stack,
    this solution is much more space consuming than the other ones */
}

// The same can be achieved with a loop
int sum_loop(int n)
{
    int i;
    int sum = 0;
    for (i = 1; i <= n; i++)
    {
        sum = sum + i; // Time complexity: O(n)
    }
    return sum;
}

// This operation can also be done using the formula
int sum_formula(int n)
{
    return n * (n + 1) / 2; // Time complexity is constant: O(1)
}
int main()
{
    printf("%d\n", sum_recursion(7));
    printf("%d\n", sum_loop(7));
    printf("%d\n", sum_formula(7));
}
