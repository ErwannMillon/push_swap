/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:08:17 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/19 20:04:50 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *a)
{
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

t_arr	add_input_to_path(t_arr path, char *input)
{
	t_arr		input_arr;
	const char	*operations[11] = {"pa\n", "pb\n", "sa\n", "sb\n",
		"ss\n", "rr\n", "ra\n", "rb\n", "rra\n",
		"rrb\n", "rrr\n"};
	int			i;

	input_arr.arr = malloc((sizeof(int) * 1));
	input_arr.arr[0] = -1;
	input_arr.len = 1;
	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(input, operations[i], ft_strlen(operations[i]) + 1))
		{
			input_arr.arr[0] = i + 1;
			if (DEBUG)
				ft_printf("operation %d\n", i + 1);
			return (extend_path(path, input_arr));
		}
		i++;
	}
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
