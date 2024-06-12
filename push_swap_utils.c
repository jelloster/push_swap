/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:09:39 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/11 16:18:34 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	high_i(t_stack s);

void	r_or_rr(t_stack *s, void (*r)(t_stack *), void (*rr)(t_stack *))
{
	if (high_i(*s) >= s -> top / 2)
		(*r)(s);
	else
		(*rr)(s);
}

static int	high_i(t_stack s)
{
	int	i;
	int	highest_i;
	
	i = 0;
	highest_i = s.top;
	while (i <= s.top)
	{
		if (s.arr[i] > s.arr[highest_i])
			highest_i = i;
		i++;
	}
	return (highest_i);
}
