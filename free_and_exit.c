/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:03:56 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/01 14:03:58 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(int *arr1, int *arr2)
{
	if (arr1)
		free (arr1);
	if (arr2)
		free (arr2);
	exit (1);
}

int	free_and_return(int *arr1, int *arr2, int ret)
{
	if (arr1)
		free (arr1);
	if (arr2)
		free (arr2);
	return (ret);
}
