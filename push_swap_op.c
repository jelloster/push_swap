/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:50:00 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/02 12:18:14 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	int	temp;

	if (s -> top < 2)
		return ;
	temp = s -> arr[s -> top];
	s -> arr[s -> top] = s -> arr[s -> top - 1];
	s -> arr[s -> top - 1] = temp;
	if (s -> code == A)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	max_n_min(s);
}

void	push(t_stack *s_1, t_stack *s_2)
{
	if (s_1 -> top == -1)
		return ;
	(s_2 -> top)++;
	s_2 -> arr[s_2 -> top] = s_1 -> arr[s_1 -> top];
	(s_1 -> top)--;
	if (s_2 -> code == A)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	max_n_min(s_1);
	max_n_min(s_2);
}

void	rotate(t_stack *s, int print)
{
	int	temp;

	if (s -> top <= -1)
		return ;
	temp = s->arr[s->top];
	ft_memmove(&(s->arr[1]), &(s->arr[0]), s->top * sizeof(int));
	s->arr[0] = temp;
	if (print)
	{
		if (s -> code == A)
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
	max_n_min(s);
}

void	reverse_rotate(t_stack *s, int print)
{
	int	temp;

	if (s->top <= 0)
		return ;
	temp = s->arr[0];
	ft_memmove(&(s->arr[0]), &(s->arr[1]), s->top * sizeof(int));
	s->arr[s->top] = temp;
	if (print)
	{
		if (s -> code == A)
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
	max_n_min(s);
}
