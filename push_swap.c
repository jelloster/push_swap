/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:21:42 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/13 14:10:25 by jelloster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	╔════════════════════════════════════════════════════════════╗
	║                         push_swap                          ║
	║                                                            ║
	║     Sort numbers in stack a into ascending order using     ║
	║              the smallest number of set operations.        ║
	║                                                            ║
	╚════════════════════════════════════════════════════════════╝
 */

#include "push_swap.h"

static int	check_order(t_pusw *pusw);
int		stupid_sort(t_stack *s, t_pusw *pusw);

void	push_swap(t_pusw *pusw)
{
	stupid_sort(&(pusw->s_a), pusw);
}

int	stupid_sort(t_stack *s, t_pusw *pusw)
{
	int	h_i = high_i(*s);
	int	h_n = s->arr[h_i];
	int	nh_i = n_high_i(*s, h_i);
	int	nh_n = s->arr[nh_i];

	while (!check_order(pusw)) // until in order
	{
		// move next highest next to set highest
		while (nh_i != h_i + 1
			&& !(nh_i == 0 && h_i == s->top))
		{
			n2top(s, &ra, &rra, nh_n);
			sa(s);
			h_i = find_num_i(*s, h_n);
			nh_i = n_high_i(*s, h_i);
			//print_stacks(pusw);
		}
		// move lowest to top
		n2top(s, &ra, &rra, s->arr[low_i(*s)]);
		h_i = find_num_i(*s, h_n);
		nh_i = n_high_i(*s, h_i);

		// set highest to next highest
		h_i = nh_i; // set h_i to n_hi
		h_n = s->arr[h_i];
		nh_i = n_high_i(*s, h_i);
		nh_n = s->arr[nh_i];
	}
	ft_printf("\nThe stack is ordered!\n");
	print_stacks(pusw);
	return (0);
}

static int	check_order(t_pusw *pusw)
{
	int	i;
	
	if (pusw->s_a.top != pusw -> n-1)
		return 0;
	i = 0;
	while (i <= pusw -> s_a.top - 1)
	{
		if (pusw -> s_a.arr[i] < pusw -> s_a.arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
