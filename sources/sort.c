/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uterese <uterese@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:33:14 by uterese           #+#    #+#             */
/*   Updated: 2021/07/31 20:00:52 by uterese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	forthree(t_stack *a, t_stack *b)
{
	if (check_sort(0, a))
		return ;
	else if (a->n == 2)
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

void	forfourteen(t_stack *a, t_stack *b)
{
	int	smallest;
	int	i;
	int	j;

	i = 0;
	smallest = ft_min(a);
	while (a->n != 3 && ++smallest && ++i)
	{
		j = 0;
		while (a->number[j] != smallest - 1)
			j++;
		if (j <= a->n / 2)
			while (j--)
				rm(a, b, 'a');
		else
			while (j++ < a->n)
				rrm(a, b, 'a');
		pm(a, b, 'b');
	}
	forthree(a, b);
	while (i--)
		pm(a, b, 'a');
}

void	move_block(t_stack *a, t_stack *b, int start, int end)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= a->n / 2)
		if (a->number[i] > start && a->number[i] <= end)
			break ;
	j = a->n;
	while (--j > a->n / 2)
		if (a->number[j] > start && a->number[j] <= end)
			break ;
	if (i <= a->n - j)
		while (i--)
			rm(a, b, 'a');
	else
		while (j++ < a->n)
			rrm(a, b, 'a');
	pm(a, b, 'b');
	if (b->n > 1)
		if (b->number[0] < b->number[1])
			sm(a, b, 'b');
}

static	void	move_back(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	while (b->number[i] != num)
		i++;
	if (i <= b->n / 2)
		while (i--)
			rm(a, b, 'b');
	else
		while (i++ < b->n)
			rrm(a, b, 'b');
	pm(a, b, 'a');
}

void	for170(t_stack *a, t_stack *b, int nb)
{
	int	smallest;
	int	range;
	int	j;
	int	i;

	i = -1;
	range = a->n / nb;
	smallest = ft_min(a) - 1;
	while (++i < nb)
	{
		j = 0;
		while (j++ < range)
			move_block(a, b, smallest + i * range, smallest + (i + 1) * range);
	}
	if (a->n > 1)
	{
		if (a->n <= 3)
			forthree(a, b);
		else
			forfourteen(a, b);
	}
	i = b->n + 1;
	while (--i)
		move_back(a, b, i);
}
