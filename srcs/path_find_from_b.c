/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind_from_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:05:25 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/07 14:04:22 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr	pathfind_from_b(t_node *num, t_node **a, t_node **b, int copy)
{
	t_arr		path;
	t_node		*tmp_a;
	t_node		*tmp_b;

	path.arr = NULL;
	path.len = 0;
	if (copy)
	{
		tmp_a = list_copy(*a);
		tmp_b = list_copy(*b);
		a = &tmp_a;
		b = &tmp_b;
	}
	if (get_list_index(num->next_in_sorted, *a) != -1)
		path = reinsert_before_target(num, a, b);
	else if (get_list_index(num->previous_in_sorted, *a) != -1)
		path = reinsert_after_target(num, a, b);
	else
		path = reinsert_before_closest(num, a, b);
	if (copy)
	{
		ft_free_list(*a);
		ft_free_list(*b);
	}
	return (path);
}

t_arr	reinsert_sort(t_node **a, t_node **b)
{
	t_node	*current;
	t_arr	min_path;
	t_arr	current_path;
	t_arr	final_path;
	t_node	*min_num;

	final_path.len = 0;
	final_path.arr = NULL;
	min_path.arr = NULL;
	while (*b)
	{
		current = *b;
		while (current && get_list_index(current->num, *b) != -1)
		{
			current_path = pathfind_from_b(current, a, b, 1);
			if (min_path.arr == NULL || (current_path.len < min_path.len && current_path.len > 0))
			{
				min_num = current;
				min_path = current_path;
			}
			else
				free (current_path.arr);
			current = current->next;
		}
		final_path = extend_path(final_path, pathfind_from_b(min_num, a, b, 0));
		free(min_path.arr);
		min_path.arr = NULL;
	}
	return (final_path);
}
