/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:21:10 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/19 15:00:48 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *s_b)
{
	swap(s_b);
	ft_printf("sb\n");
}

void	pb(t_stack *s_a, t_stack *s_b)
{
	push(s_a, s_b);
	ft_printf("pb\n");
}

void	rb(t_stack *s_b)
{
	rotate(s_b);
	ft_printf("rb\n");
}

void	rrb(t_stack *s_b)
{
	reverse_rotate(s_b);
	ft_printf("rrb\n");
}
