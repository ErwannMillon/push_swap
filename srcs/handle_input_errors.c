/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/07 14:29:23 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int_lim(char *arg)
{
	int			check;
	int			check_copy;
	int			s_len;
	int			i;
	int			minus;

	minus = 0;
	i = 0;
	check = ft_atoi(arg);
	check_copy = check;
	s_len = ft_strlen(arg);
	if (arg[0] == '+' || arg[0] == '-')
		s_len--;
	if (arg[0] == '-')
		minus = -1;
	while (check)
	{
		i++;
		check /= 10;
	}
	if (arg[0] != '0' && (i != s_len || ft_atoi(arg) != check_copy
			|| (minus && check_copy > 0) || (!minus && check_copy < 0)))
		return (1);
	return (0);
}

void	check_if_int(char *arg)
{
	int			i;

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
	if (i == 1 && (arg[0] == '-' || arg[0] == '+'))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (check_int_lim(arg))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
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
