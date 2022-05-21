/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_unsorted_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:44:36 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/21 14:25:30 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr	chunk_check(t_arr subarray, t_arr arr, t_arr unsorted, t_arr moved)
{
	if (arr.len > 200)
	{
		subarray.arr = unsorted.arr;
		subarray.len = (unsorted.len) / 2 + moved.len;
	}
	return (subarray);
}

int	get_num_to_push(t_arr sub, t_node *a, t_arr moved)
{
	int	min_len;
	int	num_to_push;
	int	i;

	i = 0;
	while (i < sub.len)
	{
		if (i == 0 ||
			(min(dist_to_bottom(sub.arr[i], a), dist_to_top(sub.arr[i], a)) < min_len)
			&& ft_get_arr_index(sub.arr[i], moved.arr, moved.len) == -1)
		{
			min_len = min(dist_to_bottom(sub.arr[i], a) + 1, dist_to_top(sub.arr[i], a));
			num_to_push = sub.arr[i];
		}
		i++;
	}
	return (num_to_push);
}

void	init_move_unsorted_arrs(t_arr *unsorted, t_arr *moved, t_arr *sub, t_arr *path)
{
	// moved.arr = malloc((unsorted.len + 1) * sizeof(int));
	// moved.len = 0;
	// ft_bubble_sort(unsorted.arr, unsorted.len);
	// sub = unsorted;

	moved->arr = malloc((unsorted->len + 1) * sizeof(int));
	moved->len = 0;
	ft_bubble_sort(unsorted->arr, unsorted->len);
	path->arr = NULL;
	path->len = 0;
	*sub = *unsorted;
}

t_arr	move_unsorted_to_b(t_node *a, t_node *b, t_arr arr, t_arr lis)
{
	t_arr	unsorted;
	t_arr	moved;
	t_arr	sub;
	t_arr	path;
	int		num_to_push;

	unsorted = unsorted_lis_filter(lis, arr);
	init_move_unsorted_arrs(&unsorted, &moved, &sub, &path);
	while (moved.len + 1 != unsorted.len)
	{
		sub = chunk_check(sub, arr, unsorted, moved);
		num_to_push = get_num_to_push(sub, a, moved);
		path = extend_path(path, move_to_top(num_to_push, a));

		moved.arr[moved.len] = num_to_push;
		moved.len++;



	}
	moved.len++;
}