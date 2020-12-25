#include <stdio.h>
#include <stdlib.h>

// Prototype of funB to avoid compiling errors
void funB(int n); // Declaration

/* These functions will call each other until the condition in funB isn't met
They call each other in a cycle, but they stop eventually */
void funA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funA(n/2);
    }
}
int main()
{
    funA(20);

    return 0;
}
