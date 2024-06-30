#include "push_swap.h"

int	indx(t_stack s, int n)
{
	int	i;

	i = 0;
	while (i <= s.top)
	{
		if (s.arr[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

int	nh_indx(t_stack s, int n)
{
	int	i;
	int	nh_i;
	
	i = 0;
	nh_i = -1;
	while (i <= s.top)
	{
		if (s.arr[i] < n && (nh_i == -1 || s.arr[i] > s.arr[nh_i]))
			nh_i = i;
		i++;
	}
	return (nh_i);
}

//	index of one higher
int	nl_indx(t_stack s, int n)
{
	int	i;
	int	nl_i;
	
	i = 0;
	nl_i = -1;
	while (i <= s.top)
	{
		if (s.arr[i] > n && (nl_i == -1 || s.arr[i] < s.arr[nl_i]))
			nl_i = i;
		i++;
	}
	return (nl_i);
}

