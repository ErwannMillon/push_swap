/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/20 00:24:00 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*arr;
	t_arr	sortedarr;
	t_node	*a;
	t_node	*b;
	int 	test[] = {0, 9, 5, 7, 6, 10};
	const char *argv_test[] = {"pushswap", "1", "5", "2", "9", "7", "22", "-100", "4"};
	argc = 9;
	arr = parse_args_to_arr(argc, argv_test);
	sortedarr.arr = ft_bubble_sort_copy(arr, argc - 1);
	sortedarr.len = argc - 1;
	ft_print_arr(sortedarr.arr, sortedarr.len, 0);
	a = create_list(arr, argc -1, sortedarr);
	ft_print_list(a);
	lis_len(test, 6);
	
}
