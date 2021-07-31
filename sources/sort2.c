/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uterese <uterese@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:33:14 by uterese           #+#    #+#             */
/*   Updated: 2021/07/31 20:10:13 by uterese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	forthree_b(t_stack *a, t_stack *b)
{
	if (check_sort(1, b))
		return ;
	else if (b->n == 2)
		sm(a, b, 'b');
	else
	{
		if (b->number[0] > b->number[1])
		{
			rrm(a, b, 'b');
			if (b->number[0] < b->number[1])
				sm(a, b, 'b');
		}
		else
		{
			if (b->number[0] > b->number[2])
				sm(a, b, 'b');
			else
			{
				rm(a, b, 'b');
				if (b->number[0] < b->number[1])
					sm(a, b, 'b');
			}
		}
	}
}

void	forfourteen_b(t_stack *a, t_stack *b)
{
	int	biggest;
	int	i;
	int	j;

	i = 0;
	biggest = ft_max(b);
	while (b->n != 3 && --biggest && ++i)
	{
		j = 0;
		while (b->number[j] != biggest + 1)
			j++;
		if (j <= b->n / 2)
			while (j--)
				rm(a, b, 'b');
		else
			while (j++ < b->n)
				rrm(a, b, 'b');
		pm(a, b, 'a');
	}
	forthree_b(a, b);
	while (i--)
		pm(a, b, 'b');
}

static	void	move_block_b(t_stack *a, t_stack *b, int start, int end)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= b->n / 2)
		if (b->number[i] > start && b->number[i] <= end)
			break ;
	j = b->n;
	while (--j > b->n / 2)
		if (b->number[j] > start && b->number[j] <= end)
			break ;
	if (i <= b->n - j)
		while (i--)
			rm(a, b, 'b');
	else
		while (j++ < b->n)
			rrm(a, b, 'b');
	pm(a, b, 'a');
	if (a->n > 1)
		if (a->number[0] > a->number[1])
			sm(a, b, 'a');
}

static	void	move_back_b(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	while (a->number[i] != num)
		i++;
	if (i <= a->n / 2)
		while (i--)
			rm(a, b, 'a');
	else
		while (i++ < a->n)
			rrm(a, b, 'a');
	pm(a, b, 'b');
}

void	for170_b(t_stack *a, t_stack *b, int nb)
{
	int	small;
	int	range;
	int	j;
	int	i;

	i = nb;
	range = b->n / nb;
	small = ft_min(b) + b->n % nb - 1;
	while (i--)
	{
		j = 0;
		while (j++ < range)
			move_block_b(a, b, small + i * range, small + (i + 1) * range);
	}
	if (b->n > 1)
	{
		if (b->n <= 3)
			forthree_b(a, b);
		else
			forfourteen_b(a, b);
	}
	i = small;
	while (++i <= range * nb)
		move_back_b(a, b, i);
}
