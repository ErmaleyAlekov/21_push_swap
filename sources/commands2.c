/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uterese <uterese@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:33:14 by uterese           #+#    #+#             */
/*   Updated: 2021/07/31 19:45:04 by uterese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static	void	rr_push(t_stack *stack)
{
	int	ale;
	int	i;

	i = stack->n;
	ale = stack->number[stack->n - 1];
	while (--i > 0)
		stack->number[i] = stack->number[i - 1];
	stack->number[i] = ale;
}

void	rrm(t_stack *a, t_stack *b, char c)
{
	if (c == 'a' || c == 'r')
		rr_push(a);
	if (c == 'b' || c == 'r')
		rr_push(b);
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

static	void	p_push(t_stack *stack1, t_stack *stack2)
{
	int	ale;
	int	i;

	i = -1;
	ale = stack1->number[0];
	while (++i < stack1->n - 1)
		stack1->number[i] = stack1->number[i + 1];
	stack1->n--;
	i = stack2->n;
	while (i-- > 0)
		stack2->number[i + 1] = stack2->number[i];
	stack2->number[0] = ale;
	stack2->n++;
}

void	pm(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
		p_push(b, a);
	else
		p_push(a, b);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
