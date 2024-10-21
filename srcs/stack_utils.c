/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:31:54 by motuomin          #+#    #+#             */
/*   Updated: 2024/10/21 13:52:49 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	max_n_min(t_stack *s)
{
	int	i;

	if (s->top < 0)
		return ;
	i = 0;
	s->min = s->arr[s->top];
	s->max = s->arr[s->top];
	s->max_i = s->top;
	s->min_i = s->top;
	while (i <= s->top)
	{
		if (s->arr[i] > s->max)
		{
			s->max = s->arr[i];
			s->max_i = i;
		}
		if (s->arr[i] < s->min)
		{
			s->min = s->arr[i];
			s->min_i = i;
		}
		i++;
	}
}

void	n2top(t_stack *s, int n)
{
	int		n_i;
	void	(*f)(t_stack *, int);

	n_i = indx(*s, n);
	if (n_i >= s -> top / 2)
		f = &rotate;
	else
		f = &reverse_rotate;
	while (s -> arr[s -> top] != n)
		(*f)(s, 1);
}
