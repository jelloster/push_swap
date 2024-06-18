/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:21:42 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/18 15:08:19 by motuomin         ###   ########.fr       */
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
int			stupid_sort(t_stack *s, t_pusw *pusw);
void		find_cheapest_move(t_pusw *pusw);

void	push_swap(t_pusw *pusw)
{
	stupid_sort(&(pusw->s_a), pusw);
}

void	smart_sort(t_pusw *pusw)
{
	// If we have mmore than 3 numbers (change later?)
	if (pusw->s_a.top > 2)
	{
		// Push 2 numbers into b to get MIN & MAX
		pa(&(pusw->s_a),&(pusw->s_b));
		pa(&(pusw->s_a),&(pusw->s_b));
		maxs_n_mins(pusw);

		// Loop while the list is not ordered
		while (pusw->s_a.top > 2)
		{
			find_cheapest_move(pusw);
		}
	}



	//
}

int	count_cost(t_stack *s_a, t_stack *s_b, int n)
{
	int	moves;

	moves = 0;
	// Count rotations to top of stack A
	moves += n2top_c(s_a, &ra, &rra, n);
	// Count rotations of stack B

	// Count B rotats
	// If n is new biggest
	if (n > s_a -> max)
		moves += n2top_c(s_b, &rb, &rrb, s_b -> max);
	else if (n < s_b -> min)
		return (0);
		// moves += n2_bot_c();
		// lowest num to bottom
	else
		//moves += n2top_c(s_b, &ra, &rra,
		// next lowest on top of stack b
	
	// Count +1 for pushing
	moves += 1;
	return (moves);
}

// Count the cost of moving a num to stack b for each nuntrm
void	find_cheapest_move(t_pusw *pusw)
{
	int	i;
	int	*costs;

	i = 0;
	costs = malloc((pusw->s_a.top + 1) * sizeof(int));
	if (!costs)
		exit (1);
	while (i < pusw->s_a.top)
	{
		costs[i] = count_cost(&pusw->s_a, &pusw->s_b, i);
		i++;
	}
	// execute lowest cost moves
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







// sort in ascending order
int	stupid_sort(t_stack *s, t_pusw *pusw)
{
	int	h_i = high_i(*s);
	int	h_n = s->arr[h_i];
	int	nh_i = n_high_i(*s, h_i);
	int	nh_n = s->arr[nh_i];

	while (!check_order(pusw)) // until in order
	{
		while (nh_i != h_i + 1
			&& !(nh_i == 0 && h_i == s->top))
		{
			n2top(s, &ra, &rra, nh_n);
			sa(s);
			h_i = find_num_i(*s, h_n);
			nh_i = n_high_i(*s, h_i);
		}
		// move lowest to top
		n2top(s, &ra, &rra, s->arr[low_i(*s)]);
		h_i = find_num_i(*s, h_n);
		nh_i = n_high_i(*s, h_i);
		// set highest to next highest
		h_i = nh_i; // set h_i to n_hi
		h_n = nh_n;
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
