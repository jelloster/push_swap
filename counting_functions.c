/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:11:10 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/19 16:49:51 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n2top_c(t_stack *s, void (*r)(t_stack *), void (*rr)(t_stack *), int n)
{
//	ft_printf("\n n in n2top = %d\n", n);
	t_stack	t_s;
	void	(*f)(t_stack *);
	int		count;

	count = 0;
	t_s = *s;
	if (find_num_i(t_s, n) >= s -> top / 2)
		f = r;
	else
		f = rr;
	while (t_s.arr[t_s.top] != n) // infinite loop
	{
//		ft_printf("Should be %d is %d\n", n, t_s.arr[t_s.top]);
		(*f)(&t_s);
		count++;
	}
	return (count);
}

int	n2bot_c(t_stack *s, void(*r)(t_stack *), void (*rr)(t_stack *), int n)
{
	t_stack	t_s;
	void	(*f)(t_stack *);
	int		count;

	count = 0;
	t_s = *s;
	if (find_num_i(t_s, n) <= s -> top / 2)
		f = rr;
	else
		f = r;
	while (t_s.arr[0] != n)
	{
		(*f)(&t_s);
		count++;
	}
	return (count);
}
