/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uterese <uterese@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:33:14 by uterese           #+#    #+#             */
/*   Updated: 2021/07/31 19:42:09 by uterese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static	void	s_push(t_stack *stack)
{
	int	ale;

	ale = stack->number[0];
	stack->number[0] = stack->number[1];
	stack->number[1] = ale;
}

void	sm(t_stack *a, t_stack *b, char c)
{
	if (c == 'a' || c == 's')
		s_push(a);
	if (c == 'b' || c == 's')
		s_push(b);
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

static	void	r_push(t_stack *stack)
{
	int	ale;
	int	i;

	i = -1;
	ale = stack->number[0];
	while (++i < stack->n - 1)
		stack->number[i] = stack->number[i + 1];
	stack->number[i] = ale;
}

void	rm(t_stack *a, t_stack *b, char c)
{
	if (c == 'a' || c == 'r')
		r_push(a);
	if (c == 'b' || c == 'r')
		r_push(b);
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
