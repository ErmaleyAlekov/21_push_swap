/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uterese <uterese@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:33:14 by uterese           #+#    #+#             */
/*   Updated: 2021/07/31 19:50:20 by uterese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static	int	init_stack(t_stack *a, t_stack *b, int argc)
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

static	void	exit_prog(t_stack *a, t_stack *b)
{
	free(a->number);
	free(b->number);
	write(1, "Error\n", 7);
	exit(1);
}

int	check_sort(int a, t_stack *stack)
{
	int	i;

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

void	more_than_170(t_stack *a, t_stack *b, int nb)
{
	int	range;
	int	i;

	i = 0;
	range = a->n / 2;
	while (i++ < range)
		move_block(a, b, 0, range);
	for170_b(a, b, nb);
	for170(a, b, nb);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (init_stack(&a, &b, argc - 1))
		exit_prog(&a, &b);
	if (check_arg(argc, argv, &a, &b))
		exit_prog(&a, &b);
	if (check_sort(0, &a))
		return (0);
	if (a.n <= 3)
		forthree(&a, &b);
	else if (a.n <= 14)
		forfourteen(&a, &b);
	else if (a.n <= 170)
		for170(&a, &b, 6);
	else
		more_than_170(&a, &b, 9);
	return (0);
}
