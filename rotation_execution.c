#include "push_swap.h"

static void	get_b_info(t_stack s_b, int *b_n, int *b_dest, int n_a);

void	d_rot(t_stack *s_a, t_stack *s_b, int n)
{
	int	b_n;
	int	b_dest;

	get_b_info(*s_b, &b_n, &b_dest, n);
	while (find_num_i(*s_b, b_n) != b_dest
		&& find_num_i(*s_a, n) != s_a->top)
		rr(s_a, s_b);
	while (find_num_i(*s_b, b_n) != b_dest)
		rb(s_b);
	while (find_num_i(*s_a, n) != s_a->top)
		ra(s_a);
	pb(s_a, s_b);
}

void	d_rev_rot(t_stack *s_a, t_stack *s_b, int n)
{
	int	b_n;
	int	b_dest;

	get_b_info(*s_b, &b_n, &b_dest, n);
	while (find_num_i(*s_b, b_n) != b_dest
		&& find_num_i(*s_a, n) != s_a->top)
		rrr(s_a, s_b);
	while (find_num_i(*s_b, b_n) != b_dest)
		rrb(s_b);
	while (find_num_i(*s_a, n) != s_a->top)
		rra(s_a);
	pb(s_a, s_b);
}

void	ra_rrb(t_stack *s_a, t_stack *s_b, int n)
{
	int	b_n;
	int	b_dest;

	get_b_info(*s_b, &b_n, &b_dest, n);
	while (find_num_i(*s_b, b_n) != b_dest)
		rrb(s_b);
	while (find_num_i(*s_a, n) != s_a->top)
		ra(s_a);
	pb(s_a, s_b);
}

void	rra_rb(t_stack *s_a, t_stack *s_b, int n)
{
	int	b_n;
	int	b_dest;

	get_b_info(*s_b, &b_n, &b_dest, n);
	while (find_num_i(*s_b, b_n) != b_dest)
		rb(s_b);
	while (find_num_i(*s_a, n) != s_a->top)
		rra(s_a);
	pb(s_a, s_b);
}

static void	get_b_info(t_stack s_b, int *b_n, int *b_dest, int n_a)
{
	if (n_a > s_b.max)
	{
		ft_printf("\n%d is new max\n", n_a);
		*b_n = s_b.max;
		*b_dest = s_b.top;
	}
	else if (n_a < s_b.min)
	{
		ft_printf("\n%d is new min\n", n_a);
		*b_n = s_b.min;
		*b_dest = 0;
	}
	else
	{
		ft_printf("\n%d is new nothing\n", n_a);
		*b_n = s_b.arr[n_low_i(s_b, n_a)];
		*b_dest = s_b.top;
	}
}
