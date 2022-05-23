/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/23 16:41:06 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_int(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
}

void	check_if_dup(t_arr arr)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < arr.len)
	{
		k = 0;
		while (k < i)
		{
			if (arr.arr[k] == arr.arr[i])
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			k++;
		}
		i++;
	}
}
