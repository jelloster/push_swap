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

int	main(int ac, char *av[])
{
	t_pusw	pusw;

	if (ac < 2)
	{
		ft_putstr_fd("Not enough arguments.\n", 2);
		return (0);
	}
	get_nums(ac, av, &pusw);
	push_swap(&pusw);
	free(pusw.s_a.arr);
	free(pusw.s_b.arr);
	return (0);
}
