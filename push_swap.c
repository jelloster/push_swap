/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:21:42 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/19 17:51:04 by motuomin         ###   ########.fr       */
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
static void	find_cheapest_move(t_pusw *pusw);
static int	count_cost(t_stack *s_a, t_stack *s_b, int n);
void		maxs_n_mins(t_pusw *pusw);
void		max_n_min(t_stack *s);
void		smart_sort(t_pusw *pusw);
static void	exe_cheapest_move(t_stack *s_a, t_stack *s_b, int n);

void	push_swap(t_pusw *pusw)
{
	smart_sort(pusw);
	return ;
}

void	smart_sort(t_pusw *pusw)
{
	if (pusw->s_a.top > 2)
	{
		// Push 2 numbers into b to get MIN & MAX
		pb(&(pusw->s_a),&(pusw->s_b));
		pb(&(pusw->s_a),&(pusw->s_b));
		print_stacks(pusw);

		// Loop while the list is not ordered
		while (pusw->s_a.top > 2)
		{
			maxs_n_mins(pusw);
			ft_printf("s_b max %d, s_b min %d\n", pusw->s_b.max, pusw->s_b.min);
			ft_printf("s_a max %d, s_a min %d\n", pusw->s_a.max, pusw->s_a.min);
			find_cheapest_move(pusw);
			print_stacks(pusw);
		}
	}
	// Order last 3 numbers
	// bla bla bla

	// Move Stack B to stack 
	while (pusw -> s_b.top >= 0)
		pa(&pusw->s_a, &pusw->s_b);
	print_stacks(pusw);
}

// Count the cost of moving a num to stack b for each nuntrm
void	find_cheapest_move(t_pusw *pusw)
{
	int	i;
	int	*costs;
	int	low_cost_i;

	i = 0;
	low_cost_i = 0;
	costs = malloc((pusw->s_a.top + 1) * sizeof(int));
	if (!costs)
		exit (1);
	while (i < pusw->s_a.top)
	{
		costs[i] = count_cost(&pusw->s_a, &pusw->s_b, pusw->s_a.arr[i]);
		if (i > 0 && costs[i] < costs[low_cost_i])
			low_cost_i = i;
		i++;
	}
	exe_cheapest_move(&pusw->s_a, &pusw->s_b, pusw->s_a.arr[low_cost_i]);
}

static int	count_cost(t_stack *s_a, t_stack *s_b, int n)
{
	int	moves;
	int	temp;

	moves = 0;
	// Count A rotates
	moves += n2top_c(s_a, &rotate, &reverse_rotate, n);

	// Count B rotates
	if (n > s_a -> max)
		moves += n2top_c(s_b, &rotate, &reverse_rotate, s_b -> max);
	else if (n < s_b -> min)
		moves += n2bot_c(s_b, &rotate, &reverse_rotate, s_b -> min);
	else
	{
		temp = s_b -> arr[n_low_i(*s_b, low_i(*s_b))];
		moves += n2top_c(s_b, &rotate, &reverse_rotate, temp);
	}
	return (moves);
}

static void	exe_cheapest_move(t_stack *s_a, t_stack *s_b, int n)
{
	int	temp;

	// rotate A
	n2top(s_a, &ra, &rra, n);

	// rotate B
	if (n > s_a -> max)
	{
		n2top(s_b, &rb, &rrb, s_b -> max);
		ft_printf("%d is the new max.\n", n);
		ft_printf("Moving old max (%d) to top.\n", s_b -> max);
	}
	else if (n < s_b -> min)
	{
		n2bot(s_b, &rb, &rrb, s_b -> min);
		ft_printf("%d is the new min.\n", n);
		ft_printf("Moving old min (%d) to bottom.\n", s_b -> min);
	}
	else
	{
		temp = s_b -> arr[n_low_i(*s_b, n)];
		n2top(s_b, &rotate, &reverse_rotate, temp);
		ft_printf("%d is not the new min or max.\n", n);
		ft_printf("Moving next lowest num (%d) to the top.\n", temp);
	}
	// Push from A to B
	pb(s_a, s_b);
}

void	maxs_n_mins(t_pusw *pusw)
{
	max_n_min(&(pusw->s_a));
	max_n_min(&(pusw->s_b));
}

void	max_n_min(t_stack *s)
{
	int	i;

	if (s->top < 0)
		return ;
	i = 0;
	s->min = s->arr[s->top];
	s->max = s->arr[s->top];
	s->max_i = s->top;
	s->min_i = s->top;

	while (i <= s->top)
	{
		if (s->arr[i] > s->max)
		{
			s->max = s->arr[i];
			s->max_i = i;
		}
		if (s->arr[i] < s->min)
		{
			s->min = s->arr[i];
			s->min_i = i;
		}
		i++;
	}
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
