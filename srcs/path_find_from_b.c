/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find_from_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:45 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/21 19:18:10 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_arr	top_insert_before(t_node *num, t_node **a, t_node **b, t_arr path)
{
	int			i;
	const int 	num_dist_top = ft_get_list_index(num->num, *b);
	const int	num_dist_bottom = dist_to_bottom(num->num, *b);
	
	i = 0;
	if (dist_to_top(num->next_in_sorted, *a) - num_dist_top > dist_to_bottom(num->next_in_sorted, *a) + 1)
	{
		path = move_to_top(num->num, b);
		path = extend_path(path, call_n_times(&rr, RRA, dist_to_bottom(num->next_in_sorted, *a) + 1, b));
		return (extend_path(path, push_path(b, a, PA)));
	}
	while (i < num_dist_top)
	{
		if (ft_get_list_index(num->next_in_sorted, *a) != 0)
			path = extend_path(path, double_rr(a, b));
		else
			path = extend_path(path, call_n_times(&r, RB, 1, b));
		i++;
	}
	if (ft_get_list_index(num->next_in_sorted, *a) != 0)
		path = extend_path(path, call_n_times(&r, RA, dist_to_top(num->next_in_sorted, *a), a));
	return (extend_path(path, push_path(b, a, PA)));
}

t_arr	reinsert_before_target(t_node *num, t_node **a, t_node **b)
{
	const int	num_dist_top = ft_get_list_index(num->num, *b);
	const int	num_dist_bottom = dist_to_bottom(num->num, *b);
	t_arr		path;

	path.arr = NULL;
	path.len = 0;
	if (num_dist_top < num_dist_bottom + 1)
	{
		top_insert_before(num, a, b, path);
		// if (dist_to_top(num->next_in_sorted, *a) - num_dist_top
		// 	> dist_to_bottom(num->next_in_sorted, *a) + 1)
		// {
		// 	path = move_to_top(num->num, b);
		// 	path = extend_path(path, call_n_times(&rr, RRA, dist_to_bottom(num->next_in_sorted, *a) + 1, b));
		// 	return (extend_path(path, push_path(b, a, PA)));
		// }
		// while (i < num_dist_top)
		// {
		// 	if (ft_get_list_index(num->next_in_sorted, *a))
		// }
	}
}

t_arr	path_find_from_b(t_node *num, t_node **a, t_node **b, t_arr sortedarr)
{
	t_arr		path;
	const int	num_index = ft_get_list_index(num->num, *b);
	const int	num_dist_top = num_index;
	const int	num_dist_bottom = dist_to_bottom(num->num, *b);

	path.arr = NULL;
	path.len = 0;
	if (ft_get_list_index(num->next_in_sorted, *a) != -1)
	{
		path = reinsert_before_target(num, a, b);
	}
}