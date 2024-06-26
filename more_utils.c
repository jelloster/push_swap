#include "push_swap.h"

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