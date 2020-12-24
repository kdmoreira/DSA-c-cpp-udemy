#include <stdio.h>

// The output will be 321 since it prints when it's ascending
void fun1(int n)
{
    if(n > 0)
    {
        // Tail recursion
        printf("%d", n);
        fun1(n-1);
    }
}

// The output will be 123 since it prints when it's descending
void fun2(int n)
{
    if(n > 0)
    {
        // Head recursion
        fun2(n-1);
        printf("%d", n); // Executed at returning time
    }
}

int main()
{
    int x = 3;
    fun1(x);
    printf("\n");
    fun2(x);

    return 0;
}
