#include <stdio.h>
#include <stdlib.h>

void fun(n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1);
        fun(n - 1);
    }
}
int main()
{
    fun(3); // The output will be 3 2 1 1 2 1 1

    return 0;
}
