/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:11:10 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/18 15:14:08 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n2top_c(t_stack *s, void (*r)(t_stack *), void (*rr)(t_stack *), int n)
{
	t_stack	t_s;
	int		n_i;
	void	(*f)(t_stack *);
	int		count;

	count = 0;
	t_s = *s;
	n_i = find_num_i(t_s, n);
	if (n_i >= s -> top / 2)
		f = r;
	else
		f = rr;
	while (s -> arr[s -> top] != n)
	{
		(*f)(s);
		count++;
	}
	return (count);
}
// are these two the same or ??? shouldnt be
int	n2bot_c(t_stack *s, void(*r)(t_stack *), void (*rr)(t_stack *), int n)
{
	t_stack	t_s;
	int		n_i;
	void	(*f)(t_stack *);
	int		count;

	count = 0;
	t_s = *s;
	n_i = find_num_i(t_s, n);
	if (n_i <= s -> top / 2)
		f = rr;
	else
		f = r;
	while (s -> arr[s -> top] != n)
	{
		(*f)(s);
		count++;
	}
	return (count);
}
