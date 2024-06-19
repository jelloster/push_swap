/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:09:39 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/19 16:49:44 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Figure out which rotate is faster to get n on top.
void	n2top(t_stack *s, void (*r)(t_stack *), void (*rr)(t_stack *), int n)
{
	int	n_i;
	void	(*f)(t_stack *);

	n_i = find_num_i(*s, n);
	if (n_i >= s -> top / 2)
		f = r;
	else
		f = rr;
	while (s -> arr[s -> top] != n)
	{
//		ft_printf("yooo");
		(*f)(s);
	}
}

void	n2bot(t_stack *s, void (*r)(t_stack *), void (*rr)(t_stack *), int n)
{
	int	n_i;
	void	(*f)(t_stack *);

	n_i = find_num_i(*s, n);
	if (n_i <= s -> top / 2)
		f = rr;
	else
		f = r;
	while (s -> arr[0] != n)
	{
//		ft_printf("yaaaa");
		(*f)(s);
	}
}
