/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:50:00 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/11 16:30:14 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Swaps the first 2 elements at the top of a stack.
	Do nothing if there are only one or no elements.
*/

void	swap(t_stack *s)
{
	int	temp;
	
	if (s -> top < 2)
		return ;
	temp = s -> arr[0];
	s -> arr[0] = s -> arr[1];
	s -> arr[0] = temp;
}

/*
	Take the first element at the top of stack 1 and put it at the top of
	stack 2.
	Do nothing if 1 is empty	
*/

void	push(t_stack *s_1, t_stack *s_2)
{
	if (s_1 -> top == 0)
		return ;
	s_2 -> arr[s_2 -> top++] = s_2 -> arr[s_1 -> top--];
}

/*
	Shift up all elements of a stack by 1.
	The first element becomes the last one.
*/

void	rotate(t_stack *s)
{
	int	temp;

	temp = s->arr[s->top];
	ft_memmove(&(s->arr[s->top]), &(s->arr[s->top - 1]), s->top + 1);
	s->arr[0] = temp;
}

/*
	Shift down all elements of a stack by 1.
	The last element becomes the first one.
*/

void	reverse_rotate(t_stack *s)
{
	int	temp;

	temp = s->arr[0];
	ft_memmove(&(s->arr[s->top - 1]), &(s->arr[s->top]), s->top + 1);
	s->arr[s->top] = temp;
}