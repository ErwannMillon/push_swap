/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/20 15:38:03 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_lis_max(int *arr, int len, const int *lis, const int *prev)
{
	int			max_len;
	int			index_to_add;
	int			i;
	int			*results;

	results = malloc(2 * sizeof(int));
	max_len = 0;
	index_to_add = 0;
	i = 0;
	while (i < len)
	{
		if (max_len < lis[i])
		{
			max_len = lis[i];
			index_to_add = i;
		}
		i++;
	}
	results[0] = max_len;
	results[1] = index_to_add;
	return (results);
}

t_arr	get_lis_arr(int *arr, int len)
{
	const int	**len_and_prev = lis_len(arr, len);
	int			*max_and_addindex;
	int			index_to_add;
	t_arr		subsequence;
	int			max_index;

	max_and_addindex = get_lis_max(arr, len, len_and_prev[0], len_and_prev[1]);
	max_index = max_and_addindex[0] - 1;
	index_to_add = max_and_addindex[1];
	subsequence.len = max_index + 1;
	subsequence.arr = malloc((max_index + 2) * sizeof(int));
	subsequence.arr[max_index] = arr[index_to_add];
	max_index--;
	// ft_print_arr(len_and_prev[1], len);
	while (index_to_add != len_and_prev[1][index_to_add])
	{
		index_to_add = len_and_prev[1][index_to_add];
		subsequence.arr[max_index] = arr[index_to_add];
		max_index--;
	}
	free_lis_vars(len_and_prev, max_and_addindex);
	return (subsequence);
}

t_arr	get_rotating_lis(int *arr, int len)
{
	int		i;
	t_arr	max;
	t_arr	current;
	int		*rotated_arr;

	i = 1;
	max = get_lis_arr(arr, len);
	while (i < len)
	{
		rotated_arr = malloc((len + 1) * sizeof(int));
		ft_memcpy(rotated_arr, arr + i, (len - i) * sizeof(int));
		ft_memcpy(rotated_arr + (len - i), arr, i * sizeof(int));
		current = get_lis_arr(rotated_arr, len);
		if (current.len > max.len)
		{
			free(max.arr);
			max = current;
		}
		else
			free(current.arr);
		free(rotated_arr);
		i++;
	}
	// ft_print_arr(max.arr, max.len);
	return (max);
}
