#include "push_swap.h"

int	r_move(t_stack s, int start_i, int end_i)
{
	if (start_i <= end_i)
		return (end_i - start_i);
	return (s.top - start_i + end_i);
}

int	rr_move(t_stack s, int start_i, int end_i)
{
	if (start_i >= end_i)
		return (start_i - end_i);
	return (start_i + (s.top - end_i + 1));
}

int	d_rot_c(t_stack s_a, t_stack s_b, int n, int (*f)(t_stack, int, int))
{
	int	a;
	int	b;

	a = (*f)(s_a, find_num_i(s_a, n), s_a.top);
	if (n > s_b.max)
		b = (*f)(s_b, s_b.max_i, s_b.top);
	else if (n < s_b.min)
		b = (*f)(s_b, s_b.min_i, 0);
	else
		b = (*f)(s_b, n_low_i(s_b, n), s_b.top);
	if (a > b)
		return (a);
	return (b);
}

int	ra_rrb_c(t_stack s_a, t_stack s_b, int n)
{
	int	a;
	int	b;

	a = r_move(s_a, find_num_i(s_a, n), s_a.top);
	if (n > s_b.max)
		b = rr_move(s_b, s_b.max_i, s_b.top);
	else if (n < s_b.min)
		b = rr_move(s_b, s_b.min_i, 0);
	else
		b = rr_move(s_b, n_low_i(s_b, n), s_b.top);
	return (a + b);
}

int	rra_rb_c(t_stack s_a, t_stack s_b, int n)
{
	int	a;
	int	b;

	a = rr_move(s_a, find_num_i(s_a, n), s_a.top);
	if (n > s_b.max)
		b = r_move(s_b, s_b.max_i, s_b.top);
	else if (n < s_b.min)
		b = r_move(s_b, s_b.min_i, 0);
	else
		b = r_move(s_b, n_low_i(s_b, n), s_b.top);
	return (a + b);
}
