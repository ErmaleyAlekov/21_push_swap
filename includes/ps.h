/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uterese <uterese@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 12:33:14 by uterese           #+#    #+#             */
/*   Updated: 2021/07/31 20:22:34 by uterese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H
# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
	int	n;
	int	*number;
}	t_stack;

int		check_arg(int argc, char **argv, t_stack *a, t_stack *b);
int		ft_isdigit(int c);
double	ft_atod(const char *nptr);
void	sm(t_stack *a, t_stack *b, char c);
void	rm(t_stack *a, t_stack *b, char c);
void	rrm(t_stack *a, t_stack *b, char c);
void	pm(t_stack *a, t_stack *b, char c);
void	forthree(t_stack *a, t_stack *b);
int		ft_min(t_stack *stack);
void	forfourteen(t_stack *a, t_stack *b);
void	for170(t_stack *a, t_stack *b, int nb);
int		check_sort(int a, t_stack *stack);
int		ft_max(t_stack *stack);
void	move_block(t_stack *a, t_stack *b, int start, int end);
void	for170_b(t_stack *a, t_stack *b, int nb);

#endif
