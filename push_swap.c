#include "push_swap.h"

int	rra_rb_c(t_stack s_a, t_stack s_b, int n);
int	ra_rrb_c(t_stack s_a, t_stack s_b, int n);
int	d_rot_c(t_stack s_a, t_stack s_b, int n, int (*f)(t_stack, int, int));
int	rr_move(t_stack s, int start_i, int end_i);
int	r_move(t_stack s, int start_i, int end_i);

void free_n_exit(t_pusw pusw);

static void	move_cheapest_num(t_pusw *pusw, int n, int cost);
static void	b_to_a(t_pusw *pusw);
static int	count_cheapest_cost(t_stack s_a, t_stack s_b, int n);

void	push_swap(t_pusw *pusw)
{
	// Push 2 numbers from stack A to stack B
	if (pusw->s_a.top > 1)
	{
		pb(&(pusw->s_a),&(pusw->s_b));
		pb(&(pusw->s_a),&(pusw->s_b));

		// Push numbers from A to B until A is empty
		while (pusw -> s_a.top >= 0)
		{
			b_to_a(pusw);
			print_stacks(pusw);
		}
		// Move biggest number on top
		n2top(&pusw->s_b, &rb, &rrb,  pusw->s_b.max);
	}
	else
	{
		max_n_min(&pusw->s_a);
		n2top(&pusw->s_a, &ra, &rra,  pusw->s_a.min);
	}

	// Move Stack B to stack A
	while (pusw -> s_b.top >= 0)
		pa(&pusw->s_a, &pusw->s_b);
	print_stacks(pusw);
}

static void	b_to_a(t_pusw *pusw)
{
	int	*costs;
	int	cheapest_num_i;
	int	cheapest_cost;
	int	i;

	costs = malloc((pusw -> s_a.top + 1) * sizeof(int));
	if (!costs)
		free_n_exit(*pusw);
	maxs_n_mins(pusw);
	cheapest_num_i = 0;
	cheapest_cost = 0;
	i = 0;
	while (i <= pusw -> s_a.top)
	{
		costs[i] = count_cheapest_cost(pusw -> s_a, pusw -> s_b, pusw -> s_a.arr[i]);
		if (i > 0 && costs[i] < costs[cheapest_num_i])
		{
			cheapest_num_i = i;
			cheapest_cost = costs[i];
		}
		i++;
	}
	free (costs);
	move_cheapest_num(pusw, pusw -> s_a.arr[cheapest_num_i], cheapest_cost);
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
}

