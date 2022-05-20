/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:51:25 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/20 20:04:15 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_arr	move_to_top(int num, t_node *root)
{
	t_arr		path;
	int			i;
	const int	d_bottom = dist_to_bottom(num, root);
	const int	d_top = dist_to_top(num, root);

	i = 0;
	if (d_bottom + 1 < d_top)
	{
		path.arr = malloc(sizeof(int) * (d_bottom + 1));
		while (i < d_bottom + 1)
		{
			if (ft_get_list_index(num, root) == 1
				&& root->num < ft_last_elem(root)->num)
			{
				path.arr[i] = SA;
				s(&root);
				ft_print_list(root);
			}
			else
			{
				path.arr[i] = RRA;
				rr(&root);
			}
			path.len++;
			i++;
		}
	}
	else
	{
		path.arr = malloc(sizeof(int) * (d_top));
		while (i < d_top)
		{
			r(&root);
			path.arr[i] = RA;
			i++;
		}
	}
	return (path);
}