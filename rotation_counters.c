# include "push_swap.h"

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

int	d_rot_c(t_stack s_f, t_stack s_t, int n, int (*fu)(t_stack, int, int))
{
	int	f;
	int	t;

	f = (*fu)(s_f, indx(s_f, n), s_f.top);
	if (n > s_t.max)
		t = (*fu)(s_t, s_t.max_i, s_t.top);
	else if (n < s_t.min)
		t = (*fu)(s_t, s_t.min_i, 0);
	else
		t = (*fu)(s_t, nl_indx(s_t, n), s_t.top);
	if (f > t)
		return (f);
	return (t);
}

int	rf_rrt_c(t_stack s_f, t_stack s_t, int n)
{
	int	f;
	int	t;

	f = r_move(s_f, indx(s_f, n), s_f.top);
	if (n > s_t.max)
		t = rr_move(s_t, s_t.max_i, s_t.top);
	else if (n < s_t.min)
		t = rr_move(s_t, s_t.min_i, 0);
	else
		t = rr_move(s_t, nl_indx(s_t, n), s_t.top); // nl_indx
	return (f + t);
}

int	rrf_rt_c(t_stack s_f, t_stack s_t, int n)
{
	int	f;
	int	t;

	f = rr_move(s_f, indx(s_f, n), s_f.top);
	if (n > s_t.max)
		t = r_move(s_t, s_t.max_i, s_t.top);
	else if (n < s_t.min)
		t = r_move(s_t, s_t.min_i, 0);
	else
		t = r_move(s_t, nl_indx(s_t, n), s_t.top); // nl_indx
	return (f + t);
}
