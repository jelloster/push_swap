/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:56:57 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/01 14:05:36 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cheapest_push(t_stack *s_f, t_stack *s_t);
static int	cheapest_cost(t_stack s_f, t_stack s_t, int n);
static void	exe_cheapest_push(t_stack *s_f, t_stack *s_t, int n, int cost);
static int	check_order(t_stack s_a);

void	push_swap(t_stack *s_a, t_stack *s_b)
{
	if (check_order(*s_a))
		return ;
	if (s_a -> top > 2)
	{
		push(s_a, s_b);
		push(s_a, s_b);
		while (s_a -> top > 2)
			cheapest_push(s_a, s_b);
		n2top(s_b, s_b->max);
	}
	while (!check_order(*s_a) && s_a -> top > 0)
	{
		rotate(s_a, 1);
		if (s_a -> arr[s_a -> top] > s_a -> arr[s_a -> top - 1])
			swap(s_a);
		n2top(s_a, s_a -> min);
	}
	while (s_b -> top >= 0)
		cheapest_push(s_b, s_a);
	n2top(s_a, s_a->min);
}

static int	check_order(t_stack s_a)
{
	int	i;

	i = 0;
	while (i <= s_a.top - 1)
	{
		if (s_a.arr[i] < s_a.arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	cheapest_push(t_stack *s_f, t_stack *s_t)
{
	int	*costs;
	int	c_i;
	int	i;

	costs = malloc((s_f -> top + 1) * sizeof(int));
	if (!costs)
	{
		free(s_f->arr);
		free(s_t->arr);
		exit(1);
	}
	i = 0;
	c_i = 0;
	while (i < s_f -> top)
	{
		costs[i] = cheapest_cost(*s_f, *s_t, s_f -> arr[i]);
		if (i > 0 && costs[i] < costs[c_i])
			c_i = i;
		i++;
	}
	exe_cheapest_push(s_f, s_t, s_f -> arr[c_i], costs[c_i]);
	free(costs);
}

static int	cheapest_cost(t_stack s_f, t_stack s_t, int n)
{
	int	c;
	int	costs[4];
	int	i;

	costs[0] = d_rot_c(s_f, s_t, n, &r_move);
	costs[1] = d_rot_c(s_f, s_t, n, &rr_move);
	costs [2] = rf_rrt_c(s_f, s_t, n);
	costs [3] = rrf_rt_c(s_f, s_t, n);
	c = costs[0];
	i = 0;
	while (i < 4)
	{
		if (costs[i] < c)
			c = costs[i];
		i++;
	}
	return (c);
}

static void	exe_cheapest_push(t_stack *s_f, t_stack *s_t, int n, int cost)
{
	if (d_rot_c(*s_f, *s_t, n, &r_move) == cost)
		d_rot(s_f, s_t, n);
	else if (d_rot_c(*s_f, *s_t, n, &rr_move) == cost)
		d_rev_rot(s_f, s_t, n);
	else if (rf_rrt_c(*s_f, *s_t, n) == cost)
		rf_rrt(s_f, s_t, n);
	else
		rrf_rt(s_f, s_t, n);
}
