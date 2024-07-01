/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:28:46 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/01 13:28:47 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_to_info(t_stack s_to, int *to_n, int *to_dest, int n_from);

void	d_rot(t_stack *s_f, t_stack *s_t, int n)
{
	int	t_n;
	int	t_i;

	get_to_info(*s_t, &t_n, &t_i, n);
	while (indx(*s_t, t_n) != t_i && indx(*s_f, n) != s_f -> top)
		rr(s_f, s_t);
	while (indx(*s_f, n) != s_f -> top)
		rotate(s_f, 1);
	while (indx(*s_t, t_n) != t_i)
		rotate(s_t, 1);
	push(s_f, s_t);
}

void	d_rev_rot(t_stack *s_f, t_stack *s_t, int n)
{
	int	t_n;
	int	t_i;

	get_to_info(*s_t, &t_n, &t_i, n);
	while (indx(*s_t, t_n) != t_i && indx(*s_f, n) != s_f -> top)
		rrr(s_f, s_t);
	while (indx(*s_f, n) != s_f -> top)
		reverse_rotate(s_f, 1);
	while (indx(*s_t, t_n) != t_i)
		reverse_rotate(s_t, 1);
	push(s_f, s_t);
}

void	rf_rrt(t_stack *s_f, t_stack *s_t, int n)
{
	int	t_n;
	int	t_i;

	get_to_info(*s_t, &t_n, &t_i, n);
	while (indx(*s_t, t_n) != t_i)
		rotate(s_t, 1);
	while (indx(*s_f, n) != s_f->top)
		reverse_rotate(s_f, 1);
	push(s_f, s_t);
}

void	rrf_rt(t_stack *s_f, t_stack *s_t, int n)
{
	int	t_n;
	int	t_i;

	get_to_info(*s_t, &t_n, &t_i, n);
	while (indx(*s_t, t_n) != t_i)
		reverse_rotate(s_t, 1);
	while (indx(*s_f, n) != s_f->top)
		rotate(s_f, 1);
	push(s_f, s_t);
}

static void	get_to_info(t_stack s_to, int *to_n, int *to_dest, int n_from)
{
	if (n_from > s_to.max)
	{
		*to_n = s_to.max;
		if (s_to.code == B)
			*to_dest = s_to.top;
		else
			*to_dest = 0;
	}
	else if (n_from < s_to.min)
	{
		*to_n = s_to.min;
		if (s_to.code == B)
			*to_dest = 0;
		else
			*to_dest = s_to.top;
	}
	else
	{
		*to_n = s_to.arr[nl_indx(s_to, n_from)];
		*to_dest = s_to.top;
	}
}
