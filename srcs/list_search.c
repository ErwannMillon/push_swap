/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:58:30 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/23 11:55:30 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_list_index(int num, t_node *root)
{
	t_node	*current;
	int		index;

	index = 0;
	current = root;
	while (current)
	{
		if (current->num == num)
			break ;
		current = current->next;
		index++;
	}
	if (!current)
	{
		ft_printf("%d num not in list\n", num);
		return (-1);
	}
	return (index);
}

int	dist_to_top(int num, t_node *root)
{
	return (ft_get_list_index(num, root));
}

int dist_to_bottom(int num, t_node *root)
{
	const int len = ft_list_len(root);
	const int num_index = ft_get_list_index(num, root);

	return (len - num_index - 1);
}