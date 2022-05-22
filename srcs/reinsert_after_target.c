/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinsert_after_target.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:42:58 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/22 02:04:05 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr	top_insert_after(t_node *num, t_node **a, t_node **b, t_arr path)
{
	int			i;
	const int 	num_dist_top = ft_get_list_index(num->num, *b);
	const int	num_dist_bottom = dist_to_bottom(num->num, *b);
	const int	targ_dist_top = dist_to_top(num->previous_in_sorted, *a);
	const int	targ_dist_bottom = dist_to_bottom(num->previous_in_sorted, *a);
	
	i = 0;
	if (targ_dist_top + 1 - num_dist_top > targ_dist_bottom)
	{
		path = move_to_top(num->num, b);
		path = extend_path(path, call_n_times(&rr, RRA, targ_dist_bottom, a));
		return (extend_path(path, push_path(b, a, PA)));
	}
	while (i < num_dist_top)
	{
		if (ft_get_list_index(num->previous_in_sorted, *a) != ft_list_len(*a) - 1)
			path = extend_path(path, double_rr(a, b));
		else
			path = extend_path(path, call_n_times(&r, RB, 1, b));
		i++;
	}
	if (ft_get_list_index(num->previous_in_sorted, *a) != ft_list_len(*a) - 1)
		path = extend_path(path, call_n_times(&r, RA, dist_to_top(num->previous_in_sorted, *a) + 1, a));
	return (extend_path(path, push_path(b, a, PA)));
}

t_arr	bottom_insert_after(t_node *num, t_node **a, t_node **b, t_arr path)
{
	const int	num_dist_top = ft_get_list_index(num->num, *b);
	const int	num_dist_bottom = dist_to_bottom(num->num, *b);
	const int	targ_dist_top = dist_to_top(num->previous_in_sorted, *a);
	const int	targ_dist_bottom = dist_to_bottom(num->previous_in_sorted, *a);
	int			i;

	i = 0;
	if (targ_dist_bottom - num_dist_bottom + 1 > targ_dist_top)
	{
		path = extend_path(path, call_n_times(&rr, RRB, num_dist_bottom + 1, b));
		path = extend_path(path, call_n_times(&r, RA, dist_to_top(num->previous_in_sorted, *a) + 1, a));
	}
	else
	{
		while (i < num_dist_bottom + 1)
		{
			if (ft_get_list_index(num->previous_in_sorted, *a) != ft_list_len(*a) - 1)
				path = extend_path(path, double_rr(a, b));
			else
				path = extend_path(path, call_n_times(&rr, RRB, 1, b));
			i++;
		}
		if (ft_get_list_index(num->previous_in_sorted, *a) != ft_list_len(*a) - 1)
			path = extend_path(path, call_n_times(&rr, RRA, dist_to_bottom(num->previous_in_sorted, *a), a));
	}
	return (extend_path(path, push_path(b, a, PA)));
}

t_arr	reinsert_after_target(t_node *num, t_node **a, t_node **b)
{
	const int	num_dist_top = ft_get_list_index(num->num, *b);
	const int	num_dist_bottom = dist_to_bottom(num->num, *b);
	t_arr		path;
	int			i;

	i = 0;

	path.arr = NULL;
	path.len = 0;
	if (num_dist_top < num_dist_bottom)
		path = extend_path(path, top_insert_after(num, a, b, path));
	else
		path = extend_path(path, bottom_insert_after(num, a, b, path));
	return (path);
}
