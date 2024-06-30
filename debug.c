#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *s)
{
    printf("\n\n");
    if (s->code == A)
        printf("Stack A:\n");
    else
        printf("Stack B:\n");
    if (s->top < 0)
    {
        printf("Stack is empty.\n");
        return;
    }

	printf(" Bottom -> ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
	printf(" <- Top");
    printf("\n\n");
}

void print_stacks(t_pusw *p)
{
    int max_height = (p->s_a.top > p->s_b.top) ? p->s_a.top : p->s_b.top;

    for (int i = max_height; i >= 0; i--)
    {
        if (i <= p->s_a.top)
            printf("%d ", p->s_a.arr[i]);
        else
            printf("  ");
        if (i <= p->s_b.top)
            printf("%d", p->s_b.arr[i]); // this is the issue
        else
            printf(" ");

        printf("\n");
    }
	printf("_ _\n");
    printf("a b\n");
}
