/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/21 19:10:57 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_node **root)
{
	t_node	*second;
	t_node	*third;
	t_node	*first;

	if (root && *root && (*root)->next)
	{
		first = *root;
		second = (*root)->next;
		(*root)->next = (*root)->next->next;
		second->next = first;
		*root = second;
	}
	else
		ft_printf("NULL POINTEER\n");
}

void	p(t_node **src, t_node **dest)
{
	t_node	*tmp;

	if (src && *src)
	{
		tmp = *src;
		*src = (*src)->next;
		if (dest && *dest)
		{
			tmp->next = (*dest);
			*dest = tmp;
		}
		else
		{
			*dest = tmp;
			tmp->next = NULL;
		}
	}
	else
		ft_printf("NULL POINTEER\n");
}

void	rr(t_node **root)
{
	t_node	*penultimate;
	t_node	*tmp;

	if (root && *root && (*root)->next)
	{
		penultimate = *root;
		while (penultimate && penultimate->next && penultimate->next->next)
		{
			penultimate = penultimate->next;
		}
		if (penultimate->next)
		{
			tmp = penultimate->next;
			penultimate->next = NULL;
			tmp->next = *root;
			*root = tmp;
		}
	}
	else
		ft_printf("NULL POINTEER\n");
}

void	r(t_node **root)
{
	t_node	*last;
	t_node	*tmp;

	if (root && *root && (*root)->next)
	{
		last = *root;
		while (last && last->next)
		{
			last = last->next;
		}
		if (last)
		{
			tmp = (*root)->next;
			last->next = *root;
			(*root)->next = NULL;
			*root = tmp;
		}
	}
	else
		ft_printf("NULL POINTEER\n");

}

t_arr	call_n_times(void(*f)(t_node **), int operation, int n, t_node **root)
{
	int			i;
	t_arr		path;

	i = 0;
	path.arr = malloc(n * sizeof(int));
	path.len = 0;
	while (i < n)
	{
		(*f)(root);
		path.arr[i] = operation;
		path.len++;
		i++;
	}
	return (path);
}

t_arr double_r(t_node **a, t_node **b)
{
	t_arr		path;

	path.arr = malloc(1 * sizeof(int));
	path.len = 1;
	path.arr[0] = RR;
	r(a);
	r(b);
	return (path);
}

t_arr double_rr(t_node **a, t_node **b)
{
	t_arr		path;

	path.arr = malloc(1 * sizeof(int));
	path.len = 1;
	path.arr[0] = RRR;
	rr(a);
	rr(b);
	return (path);
}