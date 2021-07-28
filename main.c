# include "ps.h"
# include <stdio.h>

static int init_stack(t_stack *a, t_stack *b, int argc)
{
    a->n = argc;
    a->number = malloc(argc * sizeof(int));
    if (!a->number)
        return (1);
    b->n = 0;
    b->number = malloc(argc * sizeof(int));
    if (!b->number)
    {
        free(a->number);
        return (1);
    }
    return (0);
}

static void exit_prog(t_stack *a, t_stack *b)
{
    free(a->number);
    free(b->number);
    write(1, "Error\n", 7);
    exit(1);
}

static int check_sort(int a, t_stack *stack)
{
    int i;

    i = -1;
    while (++i < stack->n - 1)
    {
        if (!(a) && stack->number[i] > stack->number[i + 1])
            return (0);
        if (a && stack->number[i] < stack->number[i + 1])
            return (0);
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    // int i = 0;
    // int j = 0;

    if (init_stack(&a, &b, argc - 1))
        exit_prog(&a, &b);
    if (check_arg(argc, argv, &a, &b))
        exit_prog(&a, &b);
    if (check_sort(0, &a))
        return (0);
    if (a.n <= 3)
        forthree(&a, &b);
    // sm(&a, &b, 'a');
    // pm(&a, &b, 'a');
    // while (i < a.n)
    //     printf("a->%d ", a.number[i++]);
    // // while (j < a.n)
    // //     printf("b->%d ", b.number[j++]);
    // printf("\n");
    return (0);
}