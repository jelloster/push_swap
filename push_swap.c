#include "push_swap.h"

static void	move_cheapest_num(t_pusw *pusw, int n, int cost);
static void	a_to_b(t_pusw *pusw);
static int	count_cheapest_cost(t_stack s_a, t_stack s_b, int n);
static int	check_order(t_pusw *pusw);
static int is_in_array(int num, int *arr, int size);

void	push_swap(t_pusw *pusw)
{
	if (check_order(pusw))
		return ;
	if (pusw->s_a.top > 2)
	{
		pb(&(pusw->s_a),&(pusw->s_b)); // doesnt care about big 3
		pb(&(pusw->s_a),&(pusw->s_b));
		maxs_n_mins(pusw);
		while (pusw -> s_a.top > 2)
			a_to_b(pusw);
		n2top(&pusw->s_b, &rb, &rrb,  pusw->s_b.max);
	}
	else
	{
		max_n_min(&pusw->s_a);
		n2top(&pusw->s_a, &ra, &rra,  pusw->s_a.min);
	}
	while(!check_order(pusw) && pusw->s_a.top > 0)
	{
		ra(&pusw->s_a);
		if (pusw->s_a.arr[pusw->s_a.top] > pusw->s_a.arr[pusw->s_a.top-1])
			sa(&pusw->s_a);
		n2top(&pusw->s_a, &ra, &rra,  pusw->s_a.min);
		print_stacks(pusw);
	}
	while (pusw -> s_b.top >= 0)
		pa(&pusw->s_a, &pusw->s_b);
}

void	get_big_three(int *arr, int big[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		big[i] = arr[i];
		i++;
	}
	while (i < size)
	{
		j = 0;
		while (j < 3)
		{
			if (arr[i] > big[j])
				big[j] = arr[i];
			j++;
		}
		i++;
	}
}

static void	a_to_b(t_pusw *pusw)
{
	int	*costs;
	int	cheapest_num_i;
	int	cheapest_cost;
	int	i;
	int	big_three[3];

	get_big_three(pusw->s_a.arr, big_three, pusw->n);
	costs = malloc((pusw -> s_a.top + 1) * sizeof(int));
	if (!costs)
		free_n_exit(*pusw);
	cheapest_num_i = 0;
	cheapest_cost = 0;
	i = 0;
	while (i <= pusw -> s_a.top)
	{
		costs[i] = count_cheapest_cost(pusw -> s_a, pusw -> s_b, pusw -> s_a.arr[i]);
		if (i > 0 && costs[i] < costs[cheapest_num_i]
			&& !is_in_array(pusw->s_a.arr[i], big_three, 3))
		{
			cheapest_num_i = i;
			cheapest_cost = costs[i];
		}
		i++;
	}
	free (costs);
	move_cheapest_num(pusw, pusw -> s_a.arr[cheapest_num_i], cheapest_cost);
}

static int is_in_array(int num, int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

static int	count_cheapest_cost(t_stack s_a, t_stack s_b, int n)
{
	int	cheapest_move;
	int	temp;

	cheapest_move = d_rot_c(s_a, s_b, n, &r_move);
	temp = d_rot_c(s_a, s_b, n, &rr_move);
	if (temp < cheapest_move)
		cheapest_move = temp;
	temp = ra_rrb_c(s_a, s_b, n);
	if (temp < cheapest_move)
		cheapest_move = temp;
	temp = rra_rb_c(s_a, s_b, n);
	if (temp < cheapest_move)
		cheapest_move = temp;
	return (cheapest_move);
}

static void	move_cheapest_num(t_pusw *pusw, int n, int cost)
{
	if (d_rot_c(pusw->s_a, pusw->s_b, n, &r_move) == cost)
		d_rot(&pusw->s_a, &pusw->s_b, n);
	else if (d_rot_c(pusw->s_a, pusw->s_b, n, &rr_move) == cost)
		d_rev_rot(&pusw->s_a, &pusw->s_b, n);
	else if (ra_rrb_c(pusw->s_a, pusw->s_b, n) == cost)
		ra_rrb(&pusw->s_a, &pusw->s_b, n);
	else
		rra_rb(&pusw->s_a, &pusw->s_b, n);
	maxs_n_mins(pusw);
}

static int	check_order(t_pusw *pusw)
{
	int	i;

	//if (pusw->s_a.top != pusw -> n-1)
	//	return 0;
	i = 0;
	while (i <= pusw -> s_a.top - 1)
	{
		if (pusw -> s_a.arr[i] < pusw -> s_a.arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
