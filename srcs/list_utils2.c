/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:37:07 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/21 17:29:52 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_path(t_arr path)
{
	int	i;
	const char	*s[] = {"x", "pa", "pb", "sa", "sb", "ss", "rr",
		"ra", "rb", "rrb", "rra", "rrr"};

	i = 0;
	while (i < path.len)
	{
		ft_printf("s[path.arr[i]]: %s\n", s[path.arr[i]]);
		i++;
	}
}
