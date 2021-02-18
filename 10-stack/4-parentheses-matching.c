#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *s;
};

int is_balanced(char *exp)
{
    struct Stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(&st, exp[i]);
            st.top++;
        }
        else if (exp[i] == ')')
        {
            if (is_empty(st))
            {
                return 0;
            }
            pop(&st);
        }
    }
    return is_empty(st) ? 1 : 0;
}

void push(struct Stack *st, char c) // O(1)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = c;
    }
}

int pop(struct Stack *st)
{
    int popped = -1;
    if (st->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        popped = st->s[st->top];
        st->top--;
    }
    return popped;
}

int is_empty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int main(void)
{
    char *exp = "((a+b)*(c-d))";

    struct Stack st;

    printf("%d", is_balanced(exp));

    return 0;
}
