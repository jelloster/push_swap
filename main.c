/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:00:04 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/13 08:49:24 by jelloster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	reverse_array(int *arr, int size);

int	main(int ac, char *av[])
{
	t_pusw	pusw;

	if (ac < 2)
	{
		// If no parameters are specified, the program must not
		// display anything and give the prompt back (?)
		return (0);
	}
	if (!get_nums(ac, av, &pusw))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	reverse_array(pusw.s_a.arr, pusw.n);
	push_swap(&pusw);
	ft_printf("The stack is ordered!\n");
	print_stacks(&pusw);
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
