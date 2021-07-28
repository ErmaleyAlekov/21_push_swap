#ifndef P_S_H
# define P_S_H
# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
    int n;
    int *number;
}   t_stack;

int     check_arg(int argc, char **argv, t_stack *a, t_stack *b);
int     ft_isdigit(int c);
int     ft_isspace(int c);
double	ft_atod(const char *nptr);
void    sm(t_stack *a, t_stack *b, char c);
void    rm(t_stack *a, t_stack *b, char c);
void    rrm(t_stack *a, t_stack *b, char c);
void    pm(t_stack *a, t_stack *b, char c);
void    forthree(t_stack *a, t_stack *b);

#endif