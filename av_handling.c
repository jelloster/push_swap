/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:20:46 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/14 12:39:07 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit_str(char	*str);
static int	check_nested_nums(char	*str, int *count);
static int	count_nums(int ac, char *av[]);
static int	get_array(int ac, char *av[], int *arr);

int	get_nums(int ac, char *av[], t_pusw *pusw)
{
	int	*nums;
	int	num_count;

	num_count = count_nums(ac, av);
	if (num_count == -1)
		return (0);
	pusw -> n = num_count;
	pusw -> s_a.top = num_count - 1;
	pusw -> s_b.top = -1;
	nums = malloc(num_count * sizeof(int));
	if (!nums)
		exit(1);
	if (!get_array(ac, av, nums))
	{
		free (nums);
		exit (1);
	}
	pusw -> s_a.arr = nums;
	return (1);
}

static int	get_array(int ac, char *av[], int *arr)
{
	int		arr_i;
	int		av_i;
	int		temp_i;
	char	**temp;

	arr_i = 0;
	av_i = 1;
	while (av_i <= ac - 1)
	{
		if (!ft_strchr(av[av_i], ' '))
			arr[arr_i++] = ft_atoi(av[av_i++]);
		else
		{
			temp = ft_split(av[av_i++], ' ');
			if (!temp)
			{
				free (arr);
				return (0);
			}
			temp_i = 0;
			while (temp[temp_i])
				arr[arr_i++] = ft_atoi(temp[temp_i++]);
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
		if (!ft_isdigit(str[i++]))
				return (0);
	return (1);
}
