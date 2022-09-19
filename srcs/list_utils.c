/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/19 19:26:34 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_node *root)
{
	t_node	*current;

	current = root;
	while (current)
	{
		ft_printf("%d, ", current->num);
		current = current->next;
	}
	ft_printf("\n");
}

t_node	*ft_last_elem(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_list_len(t_node *lst)
{
	int	len;

	len = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	ft_print_stacks(t_node *a, t_node *b)
{
	ft_printf("A: ");
	ft_print_list(a);
	ft_printf("B: ");
	ft_print_list(b);
	ft_printf("\n");
}
