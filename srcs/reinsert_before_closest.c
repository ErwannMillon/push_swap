/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinsert_before_closest.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:05:25 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/02 18:00:20 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_list_min(t_node *root)
{
	t_node	*current;
	t_node	*min_node;

	current = root;
	while (current)
	{
		if (current == root || current->num < min_node->num)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_node	*get_closest_greater(t_node *a, t_node *search_num, t_node *min)
{
	t_node	*current;
	int		min_num;

	current = get_list_min(a);
	min_num = current->num;
	while (current)
	{
		if (current->num > search_num->num)
			return (current);
		current = current->next;
	}
	current = a;
	while (current->num != min_num)
	{
		if (current->num > search_num->num)
			return (current);
		current = current->next;
	}
	return (min);
}

t_arr	top_insert_before_closest(t_node *num, t_node **a, t_node **b, t_arr path)
{
	int				i;
	const int		num_dist_top = ft_get_list_index(num->num, *b);
	const t_node	*target = get_closest_greater(*a, num, get_list_min(*a));

	i = 0;
	if (dist_to_top(target->num, *a) - num_dist_top > dist_to_bottom(target->num, *a) + 1)
	{
		path = move_to_top(num->num, b, RB);
		path = extend_path(path, call_n_times(&rr, RRA, dist_to_bottom(target->num, *a) + 1, a));
		return (extend_path(path, push_path(b, a, PA)));
	}
	while (i < num_dist_top)
	{
		if (ft_get_list_index(target->num, *a) != 0)
			path = extend_path(path, double_r(a, b));
		else
			path = extend_path(path, call_n_times(&r, RB, 1, b));
		i++;
	}
	if (ft_get_list_index(target->num, *a) != 0)
		path = extend_path(path, call_n_times(&r, RA, dist_to_top(target->num, *a), a));
	return (extend_path(path, push_path(b, a, PA)));
}

//INSERTS NUM_TO_PUSH BEFORE THE NEXT SORTED NUM IN A BY MOVING 
//NUM_TO_PUSH TO TOP OF B WITH REVERSE ROTATES
t_arr	bottom_insert_before_closest(t_node *num, t_node **a, t_node **b, t_arr path)
{
	const int		num_dist_top = ft_get_list_index(num->num, *b);
	const int		num_dist_bottom = dist_to_bottom(num->num, *b);
	const t_node	*target = get_closest_greater(*a, num, get_list_min(*a));
	int				i;

	i = 0;
	if (dist_to_bottom(target->num, *a) + 1 > dist_to_top(target->num, *a))
	{
		path = extend_path(path, call_n_times(&rr, RRB, num_dist_bottom + 1, b));
		path = extend_path(path, call_n_times(&r, RA, dist_to_top(target->num, *a), a));
	}
	else
	{
		while (i < num_dist_top)
		{
			if (ft_get_list_index(target->num, *a) != 0)
				path = extend_path(path, double_r(a, b));
			else
				path = extend_path(path, call_n_times(&rr, RRB, 1, b));
			i++;
		}
		if (ft_get_list_index(target->num, *a) != 0)
			path = extend_path(path, call_n_times(&rr, RRA, dist_to_bottom(target->num, *a) + 1, a));
	}
	return (extend_path(path, push_path(b, a, PA)));
}

t_arr	reinsert_before_closest(t_node *num, t_node **a, t_node **b)
{
	const int	num_dist_top = ft_get_list_index(num->num, *b);
	const int	num_dist_bottom = dist_to_bottom(num->num, *b);
	t_arr		path;
	int			i;

	i = 0;
	path.arr = NULL;
	path.len = 0;
	if (num_dist_top < num_dist_bottom + 1)
		path = extend_path(path, top_insert_before_closest(num, a, b, path));
	else
		path = extend_path(path, bottom_insert_before_closest(num, a, b, path));
	return (path);
}
