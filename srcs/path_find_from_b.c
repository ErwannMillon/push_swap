/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find_from_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:39:45 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/20 23:45:34 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_arr	path_find_from_b(t_node *num, t_node *a, t_node *b, t_arr sortedarr)
{
	t_arr		path;
	const int	num_index = ft_get_list_index(num->num, b);
	const int	num_dist_top = num_index;
	const int	num_dist_bottom = dist_to_bottom(num->num, b);

	if (ft_get_list_index(num->next_in_sorted, a) != -1)
	{
		path = reinsert_before_target(num, a, b, sortedarr)
	}
}