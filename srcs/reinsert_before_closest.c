/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinsert_before_closest.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:05:25 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/22 00:43:47 by gmillon          ###   ########.fr       */
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
	t_node *current;
	int		min;

	current = get_list_min(a);
	min = current->num;
	
	while (current)
	{
		if (current->num > search_num->num)
			return(current);
		current = current->next;
	}
	current = a;
	while (current->num != min)
	{
		if (current->num > search_num->num)
			return(current);
		current = current->next;
	}
	return (min);
}

t_arr	reinsert_before_closest(t_node *num, t_node **a, t_node **b)
{
	const t_node *target = get_closest_greater(a, num, get_list_min(a));

}
