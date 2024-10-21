/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:23:28 by motuomin          #+#    #+#             */
/*   Updated: 2024/10/21 13:51:52 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rr(t_stack *s_a, t_stack *s_b)
{
	rotate(s_a, 0);
	rotate(s_b, 0);
	ft_printf("rr\n");
}

void	rrr(t_stack *s_a, t_stack *s_b)
{
	reverse_rotate(s_a, 0);
	reverse_rotate(s_b, 0);
	ft_printf("rrr\n");
}
