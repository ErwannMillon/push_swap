/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinsert_before_target.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:45 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/19 13:04:33 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//INSERTS NUM BEFORE THE NEXT SORTED NUM IN A 
// BY MOVING NUM_TO_PUSH TO TOP OF B WITH ROTATES
t_arr	top_insert_before(t_node *num, t_node **a, t_node **b, t_arr path)
{
	int			i;
	const int 	d_top = get_list_index(num->num, *b);

	i = 0;
	if (dist_top(num->next_sorted, *a) - d_top > \
		dist_bottom(num->next_sorted, *a) + 1)
	{
		path = move_to_top(num->num, b, RB);
		path = extend_path(path, \
		call_n_times(&rr, RRA, dist_bottom(num->next_sorted, *a) + 1, a));
		path = extend_path(path, push_path(b, a, PA));
		return (path);
	}
	while (i < d_top)
	{
		if (get_list_index(num->next_sorted, *a) != 0)
			path = extend_path(path, double_r(a, b));
		else
			path = extend_path(path, call_n_times(&r, RB, 1, b));
		i++;
	}
	if (get_list_index(num->next_sorted, *a) != 0)
		path = extend_path(path, \
		call_n_times(&r, RA, dist_top(num->next_sorted, *a), a));
	return (extend_path(path, push_path(b, a, PA)));
}

//INSERTS NUM_TO_PUSH BEFORE THE NEXT SORTED NUM IN A BY MOVING 
//NUM_TO_PUSH TO TOP OF B WITH REVERSE ROTATES
t_arr	bottom_insert_before(t_node *num, t_node **a, t_node **b, t_arr path)
{
	const int	d_top = get_list_index(num->num, *b);
	const int	d_bottom = dist_bottom(num->num, *b);
	int			i;

	i = 0;
	if (dist_bottom(num->next_sorted, *a) + 1 - d_bottom > \
		dist_top(num->next_sorted, *a))
	{
		path = extend_path(path, call_n_times(&rr, RRB, d_bottom + 1, b));
		path = extend_path(path, \
			call_n_times(&r, RA, dist_top(num->next_sorted, *a), a));
	}
	else
	{
		while (i < d_top)
		{
			if (get_list_index(num->next_sorted, *a) != 0)
				path = extend_path(path, double_r(a, b));
			else
				path = extend_path(path, call_n_times(&rr, RRB, 1, b));
			i++;
		}
		if (get_list_index(num->next_sorted, *a) != 0)
			path = extend_path(path, \
			call_n_times(&rr, RRA, dist_bottom(num->next_sorted, *a) + 1, a));
	}
	return (extend_path(path, push_path(b, a, PA)));
}

t_arr	reinsert_before_target(t_node *num, t_node **a, t_node **b)
{
	const int	d_top = get_list_index(num->num, *b);
	const int	d_bottom = dist_bottom(num->num, *b);
	t_arr		path;
	int			i;

	i = 0;
	path.arr = NULL;
	path.len = 0;
	if (d_top < d_bottom + 1)
		path = extend_path(path, top_insert_before(num, a, b, path));
	else
		path = extend_path(path, bottom_insert_before(num, a, b, path));
	return (path);
}
