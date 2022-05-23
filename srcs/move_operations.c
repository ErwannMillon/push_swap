/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:51:25 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/23 13:45:59 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr	rr_to_top(int num, t_node **root, t_arr path)
{
	const int	d_bottom = dist_to_bottom(num, *root);
	int			i;

	i = 0;
	while (i < d_bottom + 1)
	{
		if (ft_get_list_index(num, *root) == 1
			&& (*root)->num < ft_last_elem((*root))->num)
		{
			path.arr[i] = SA;
			s(root);
			ft_print_list(*root);
		}
		else
		{
			path.arr[i] = RRA;
			rr(root);
		}
		path.len++;
		i++;
	}
	return (path);
}

t_arr	move_to_top(int num, t_node **root)
{
	t_arr		path;
	const int	d_bottom = dist_to_bottom(num, *root);
	const int	d_top = dist_to_top(num, *root);
	int			i;

	path.len = 0;
	i = 0;
	if (d_bottom + 1 < d_top)
	{
		path.arr = malloc(sizeof(int) * (d_bottom + 1));
		path = rr_to_top(num, root, path);
	}
	else
		path = call_n_times(&r, RA, d_top, root);
	return (path);
}

t_arr move_min_to_start(t_node **root)
{
	t_arr	path;
	t_node	*min_node = get_list_min(*root);

	path.arr = NULL;
	path.len = 0;
	path = move_to_top(min_node->num, root);
	return (path);
}

// t_arr move_to_beginning(t_node *root, t_arr sortedarr)
// {
// 	t_arr		path;
// 	const int	target_index = ft_get_list_index(sortedarr.arr[0], root);
// 	//POTENTIAL BUG FROM FUNCTION REUSE
// 	if (target_index != 0)
// 	{
// 		if 
// 	}

// }