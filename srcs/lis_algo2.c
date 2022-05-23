/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algo2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/23 16:24:03 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_lis_arrays(int *lis, int *prev_index, int i, int j)
{
	lis[i] = lis[j] + 1;
	prev_index[i] = j;
}

void	init_lis_arrays(int *lis, int *prev_index, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		lis[i] = 1;
		prev_index[i] = i;
		i++;
	}
}

const int	**lis_len(const int *arr, int len)
{
	int			*lis;
	int			*prev_index;
	int			i;
	int			j;
	int			**results;

	i = 1;
	lis = malloc(sizeof(int) * (len + 1));
	prev_index = malloc(sizeof(int) * (len + 1));
	init_lis_arrays(lis, prev_index, len);
	results = malloc(sizeof(int *) * 2);
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				update_lis_arrays(lis, prev_index, i, j);
			j++;
		}
		i++;
	}
	results[0] = lis;
	results[1] = prev_index;
	return ((const int **)results);
}

t_arr	unsorted_lis_filter(t_arr lis, t_arr a)
{
	int		i;
	int		k;
	t_arr	unsorted;

	unsorted.arr = malloc(a.len * sizeof(int));
	i = 0;
	k = 0;
	while (i < a.len)
	{
		if (ft_get_arr_index(a.arr[i], lis.arr, lis.len) == -1)
		{
			unsorted.arr[k] = a.arr[i];
			k++;
		}
		i++;
	}
	unsorted.len = k;
	return (unsorted);
}
