/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:21:10 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/19 15:28:08 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *s_a)
{
	swap(s_a);
	ft_printf("sa\n");
}

void	pa(t_stack *s_a, t_stack *s_b)
{
	push(s_b, s_a);
	ft_printf("pa\n");
}

void	ra(t_stack *s_a)
{
	rotate(s_a);
	ft_printf("ra\n");
}

void	rra(t_stack *s_a)
{
	reverse_rotate(s_a);
	ft_printf("rra\n");
}
