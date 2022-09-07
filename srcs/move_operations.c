/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:51:25 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/07 14:40:38 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr	rr_to_top(int num, t_node **root, t_arr path, int operation)
{
	const int	d_bottom = dist_bottom(num, *root);
	int			i;

	i = 0;
	while (i < d_bottom + 1)
	{
		if (get_list_index(num, *root) == 1
			&& (*root)->num < ft_last_elem((*root))->num)
		{
			path.arr[i] = SA;
			s(root);
			ft_print_list(*root);
		}
		else
		{
			if (operation == RA)
				path.arr[i] = RRA;
			else
				path.arr[i] = RRB;
			rr(root);
		}
		path.len++;
		i++;
	}
	return (path);
}

t_arr	move_to_top(int num, t_node **root, int operation)
{
	t_arr		path;
	const int	d_bottom = dist_bottom(num, *root);
	const int	d_top = dist_top(num, *root);

	path.len = 0;
	if (d_bottom + 1 < d_top)
	{
		path.arr = malloc(sizeof(int) * (d_bottom + 1));
		path = rr_to_top(num, root, path, operation);
	}
	else
		path = call_n_times(&r, operation, d_top, root);
	return (path);
}

t_arr	move_min_to_start(t_node **root)
{
	t_arr	path;
	t_node	*min_node;

	min_node = get_list_min(*root);
	path.arr = NULL;
	path.len = 0;
	path = move_to_top(min_node->num, root, RA);
	return (path);
}

// t_arr move_to_beginning(t_node *root, t_arr sortedarr)
// {
// 	t_arr		path;
// 	const int	target_index = get_list_index(sortedarr.arr[0], root);
// 	//POTENTIAL BUG FROM FUNCTION REUSE
// 	if (target_index != 0)
// 	{
// 		if 
// 	}

// }