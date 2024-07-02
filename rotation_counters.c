/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_counters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:28:26 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/02 11:23:00 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Counts rotation moves required to go from start_i to end_i
int	r_move(t_stack s, int start_i, int end_i)
{
	if (start_i <= end_i)
		return (end_i - start_i);
	return (s.top - start_i + end_i);
}

// Counts reverse_ rotation moves required to go from start_i to end_i
int	rr_move(t_stack s, int start_i, int end_i)
{
	if (start_i >= end_i)
		return (start_i - end_i);
	return (start_i + (s.top - end_i + 1));
}

// Counts moves needed to get n to top in s_f (f), and the appropriate num
// in s_t to its appropriate place with rotating/revrot them at the same time +
// needed extra single rotations to get the bigger move done
int	d_rot_c(t_stack s_f, t_stack s_t, int n, int (*fu)(t_stack, int, int))
{
	int	f;
	int	t;

	f = (*fu)(s_f, indx(s_f, n), s_f.top);
	if (n > s_t.max)
	{
		if (s_t.code == B)
			t = (*fu)(s_t, s_t.max_i, s_t.top);
		else
			t = (*fu)(s_t, s_t.max_i, 0);
	}
	else if (n < s_t.min)
	{
		if (s_t.code == B)
			t = (*fu)(s_t, s_t.min_i, 0);
		else
			t = (*fu)(s_t, s_t.min_i, s_t.top);
	}
	else
	{
		if (s_t.code == B)
			t = (*fu)(s_t, nh_indx(s_t, n), s_t.top);
		else
			t = (*fu)(s_t, nl_indx(s_t, n), s_t.top);
	}
	if (f > t)
		return (f);
	return (t);
}

// Counts moves if rotating stack from and reverse rotating stack to
int	rf_rrt_c(t_stack s_f, t_stack s_t, int n)
{
	int	f;
	int	t;

	f = r_move(s_f, indx(s_f, n), s_f.top);
	if (n > s_t.max)
	{
		if (s_t.code == B)
			t = rr_move(s_t, s_t.max_i, s_t.top);
		else
			t = rr_move(s_t, s_t.max_i, 0);
	}
	else if (n < s_t.min)
	{
		if (s_t.code == B)
			t = rr_move(s_t, s_t.min_i, 0);
		else
			t = rr_move(s_t, s_t.min_i, s_t.top);
	}
	else
	{
		if (s_t.code == B)
			t = rr_move(s_t, nh_indx(s_t, n), s_t.top);
		else
			t = rr_move(s_t, nl_indx(s_t, n), s_t.top);
	}
	return (f + t);
}

// Counts moves if reverse rotating stack from and rotating stack to
int	rrf_rt_c(t_stack s_f, t_stack s_t, int n)
{
	int	f;
	int	t;

	f = rr_move(s_f, indx(s_f, n), s_f.top);
	if (n > s_t.max)
	{
		if (s_t.code == B)
			t = r_move(s_t, s_t.max_i, s_t.top);
		else
			t = r_move(s_t, s_t.max_i, 0);
	}
	else if (n < s_t.min)
	{
		if (s_t.code == B)
			t = r_move(s_t, s_t.min_i, 0);
		else
			t = r_move(s_t, s_t.min_i, s_t.top);
	}
	else
	{
		if (s_t.code == B)
			t = r_move(s_t, nh_indx(s_t, n), s_t.top);
		else
			t = r_move(s_t, nl_indx(s_t, n), s_t.top);
	}
	return (f + t);
}
