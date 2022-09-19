/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:37:07 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/19 13:01:27 by gmillon          ###   ########.fr       */
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

void	print_path_output(t_arr path)
{
	int			i;
	const char	*s[] = {"x", "pa", "pb", "sa", "sb", "ss", "rr",
		"ra", "rb", "rra", "rrb", "rrr"};

	i = 0;
	while (i < path.len)
	{
		ft_printf("%s", s[path.arr[i]]);
		if (i != path.len - 1)
			ft_printf("\n");
		i++;
	}
}

void	print_path(t_arr path)
{
	int			i;
	const char	*s[] = {"x", "pa", "pb", "sa", "sb", "ss", "rr",
		"ra", "rb", "rra", "rrb", "rrr"};

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
			copy_current->next = \
				ft_memcpy_alloc(src_current->next, sizeof(t_node));
		else
			copy_current->next = NULL;
		src_current = src_current->next;
		copy_current = copy_current->next;
	}
	return (copy_root);
}

t_arr	align_arrs(const t_node *target, t_node **a, t_node **b, t_arr path)
{
	if (get_list_index(target->num, *a) != 0)
		path = extend_path(path, double_r(a, b));
	else
		path = extend_path(path, call_n_times(&rr, RRB, 1, b));
	return (path);
}
