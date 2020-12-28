#include <stdio.h>
#include <stdlib.h>

/* In a nested recursion you must first find the
result of the nested inner call and then make the outer call */
int fun(int n)
{
    if(n > 100)
    {
        return n - 10;
    }
    return fun(fun(n + 11)); // It takes a recursive call as parameter
}

int main()
{
    int r;
    r = fun(95);
    printf("%d", r);

    return 0;
}
