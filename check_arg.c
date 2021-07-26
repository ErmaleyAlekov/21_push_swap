# include "ps.h"

static int isnumbs(int argc, char **str)
{
    int i;
    int j;

    i = 0;
    while (++i < argc)
    {
        j = -1;
        if (*(*(str + i)) == '-' || *(*(str + i)) == '+')
            j++;
        while (*(*(str + i) + ++j)) 
            if (!(ft_isdigit(*(*(str + i) + j))))
                return (1);
    }
    return (0);
}

static int isints(int argc, char **str, t_stack *stack)
{
    double num;
    int i;

    i = 0;
    while (++i < argc)
    {
        num = ft_atod(*(str + i));
        if (num < -2147483647 || num > 2147483647)
            return (1);
        stack->number[i - 1] = (int)num;
    }
    return (0);
}

static int isrepeated(t_stack *a, t_stack *b)
{
    int i;
    int j;
    int k;

    i = -1;
    j = 0;
    while (++i < a->n)
    {
        k = -1;
        while (++k < j)
            if (a->number[i] == b->number[k])
                return (1);
        b->number[j] = a->number[i];
        j++;
    }
    return (0);
}

int check_arg(int argc, char **argv, t_stack *a, t_stack *b)
{
    if (isnumbs(argc, argv))
        return (1);
    if (isints(argc, argv, a))
        return (1);
    if (isrepeated(a, b))
        return (1);
    return (0);
}