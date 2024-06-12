#include "push_swap.h"

void	ss(t_stack *s_a, t_stack *s_b)
{
	swap(s_a);
	swap(s_b);
	ft_printf("ss\n");
}

void	rr(t_stack *s_a, t_stack *s_b)
{
	rotate(s_a);
	rotate(s_b);
	ft_printf("rr\n");
}

void	rrr(t_stack *s_a, t_stack *s_b)
{
	reverse_rotate(s_a);
	reverse_rotate(s_b);
	ft_printf("rrr\n");
}
