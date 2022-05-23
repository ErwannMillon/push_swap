/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composite_stack_operations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:21:20 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/23 16:22:25 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr	call_n_times(void (*f)(t_node **), int operation, int n, t_node **root)
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

t_arr	double_r(t_node **a, t_node **b)
{
	t_arr		path;

	path.arr = malloc(1 * sizeof(int));
	path.len = 1;
	path.arr[0] = RR;
	r(a);
	r(b);
	return (path);
}

t_arr	double_rr(t_node **a, t_node **b)
{
	t_arr		path;

	path.arr = malloc(1 * sizeof(int));
	path.len = 1;
	path.arr[0] = RRR;
	rr(a);
	rr(b);
	return (path);
}
