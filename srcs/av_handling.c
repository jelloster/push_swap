/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:20:46 by motuomin          #+#    #+#             */
/*   Updated: 2024/10/21 13:51:34 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_isdigit_str(char	*str);
static int	check_nested_nums(char	*str, int *count);
static int	count_nums(int ac, char *av[]);
static int	get_array(int ac, char *av[], int *arr);

int	get_nums(int ac, char *av[], t_pusw *pusw)
{
	int	*nums_a;
	int	*nums_b;
	int	num_count;

	num_count = count_nums(ac, av);
	if (num_count == -1)
		return (0);
	pusw -> n = num_count;
	pusw -> s_a.top = num_count - 1;
	pusw -> s_b.top = -1;
	nums_a = malloc(num_count * sizeof(int));
	if (!nums_a)
		exit(1);
	nums_b = malloc(num_count * sizeof(int));
	if (!nums_b)
		free_and_exit(nums_a, NULL);
	if (!get_array(ac, av, nums_a))
		return (free_and_return(nums_a, nums_b, 0));
	pusw -> s_a.arr = nums_a;
	pusw -> s_b.arr = nums_b;
	return (1);
}

static int	get_array(int ac, char *av[], int *arr)
{
	int		a;
	int		temp_i;
	char	**temp;

	a = 0;
	while (--ac > 0)
	{
		if (!ft_strchr(*(++av), ' '))
		{
			arr[a++] = ft_atoi(*av);
			if ((arr[a - 1] == 0 || arr[a - 1] == -1) && ft_strlen(*av) > 2)
				return (free_and_return(arr, NULL, 0));
		}
		else
		{
			temp = ft_split(*av, ' ');
			if (!temp)
				free_and_exit(arr, NULL);
			temp_i = 0;
			while (temp[temp_i])
				arr[a++] = ft_atoi(temp[temp_i++]);
			free (temp);
		}
	}
	return (1);
}

static int	count_nums(int ac, char *av[])
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (i <= ac - 1)
	{
		if (!ft_strchr(av[i], ' ') && ft_isdigit_str(av[i]))
			count++;
		else if (ft_strchr(av[i], ' '))
		{
			if (!check_nested_nums(av[i], &count))
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (count);
}

static int	check_nested_nums(char	*str, int *count)
{
	char	**temp;
	int		i;

	temp = ft_split(str, ' ');
	if (!temp)
		exit (1);
	i = 0;
	while (temp[i])
	{
		if (ft_isdigit_str(temp[i]))
			(*count)++;
		else
		{
			free(temp);
			return (0);
		}
		i++;
	}
	free(temp);
	return (1);
}

static int	ft_isdigit_str(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
