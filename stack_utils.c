#include "push_swap.h"

// Find index of a given number
int	find_num_i(t_stack s, int num)
{
	int	i;

	i = 0;
	while (i <= s.top)
	{
		if (s.arr[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

// Index of highest number in the stack
int	high_i(t_stack s)
{
	int	i;
	int	highest_i;
	
	i = 0;
	highest_i = s.top;
	while (i <= s.top)
	{
		if (s.arr[i] > s.arr[highest_i])
			highest_i = i;
		i++;
	}
	return (highest_i);
}
// Index of the next highest number
int	n_high_i(t_stack s, int h_i)
{
	int	i;
	int	nh_i;
	
	i = 0;
	if (h_i != s.top)
		nh_i = s.top;
	else
		nh_i = 0;
	while (i <= s.top)
	{
		if (i != h_i)
		{
			if (s.arr[i] <= s.arr[h_i]
				&& s.arr[i] > s.arr[nh_i])
				nh_i = i;
		}
		i++;
	}
	return (nh_i);
}

int	low_i(t_stack s)
{
	int	i;
	int	lowest_i;
	
	i = 0;
	lowest_i = s.top;
	while (i <= s.top)
	{
		if (s.arr[i] < s.arr[lowest_i])
			lowest_i = i;
		i++;
	}
	return (lowest_i);
}

int	n_low_i(t_stack s, int n)
{
	int	i;
	int	nl_i;
	
	i = 0;
	nl_i = 0;
	while (n < s.arr[nl_i])
		nl_i++;
	while (i <= s.top)
	{
		if (s.arr[i] < n && s.arr[i] > s.arr[nl_i])
			nl_i = i;
		i++;
	}
	return (nl_i);
}
