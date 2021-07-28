#include "ps.h"

void    forthree(t_stack *a, t_stack *b)
{
    if (a->n == 2)
        sm(a, b, 'a');
    else
    {
        if (a->number[0] < a->number[1])
        {
            rrm(a, b, 'a');
            if (a->number[0] > a->number[1])
                sm(a, b, 'a');
        }
        else
        {
            if (a->number[0] < a->number[2])
                sm(a, b, 'a');
            else
            {
                rm(a, b, 'a');
                if (a->number[0] > a->number[1])
                    sm(a, b, 'a');
            }
        }
    }
}