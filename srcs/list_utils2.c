/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:37:07 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/23 16:24:44 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_path(t_arr path)
{
	int			i;
	const char	*s[] = {"x", "pa", "pb", "sa", "sb", "ss", "rr",
		"ra", "rb", "rrb", "rra", "rrr"};

	i = 0;
	ft_printf("PATH: \n");
	while (i < path.len)
	{
		ft_printf("%s, ", s[path.arr[i]]);
		i++;
	}
}

t_node	*list_copy(t_node *root)
{
	t_node	*copy_current;
	t_node	*src_current;
	t_node	*copy_root;

	src_current = root;
	copy_current = ft_memcpy_alloc(src_current, sizeof(t_node));
	copy_root = copy_current;
	while (src_current)
	{
		if (src_current->next)
			copy_current->next = ft_memcpy_alloc(src_current->next, sizeof(t_node));
		else
			copy_current->next = NULL;
		src_current = src_current->next;
		copy_current = copy_current->next;
	}
	return (copy_root);
}