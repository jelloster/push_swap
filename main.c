/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:53:06 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/01 14:06:15 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_array(int *arr, int size);
static int	has_duplicates(int *arr, int size);

int	main(int ac, char *av[])
{
	t_pusw	pusw;

	if (ac < 2)
		return (0);
	if (!get_nums(ac, av, &pusw) || has_duplicates(pusw.s_a.arr, pusw.n))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	reverse_array(pusw.s_a.arr, pusw.n);
	pusw.s_a.code = A;
	pusw.s_b.code = B;
	max_n_min(&pusw.s_a);
	push_swap(&pusw.s_a, &pusw.s_b);
	free(pusw.s_a.arr);
	free(pusw.s_b.arr);
	return (0);
}

static void	reverse_array(int *arr, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
		i++;
	}
}

static int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
