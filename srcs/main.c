/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/22 01:54:55 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_arr	arr;
	t_arr	sortedarr;
	t_node	*a;
	t_node	*b;
	t_arr	path;
	t_arr	lis;
	
	
	int 	test[] = {0, 9, 5, 7, 6, 10};
	char *argv_test[] = {"pushswap", "1", "5", "2", "70", "9", "7", "22", "-100", "4", "23", "61", "8", "33"};
	argc = 14;

	b = NULL;
	arr = parse_args_to_arr(argc, argv_test);
	sortedarr.arr = ft_bubble_sort_copy(arr.arr, argc - 1);
	sortedarr.len = argc - 1;
	ft_print_arr(sortedarr.arr, sortedarr.len);
	a = create_list(arr.arr, argc -1, sortedarr);
	ft_print_list(a);
	lis = get_rotating_lis(arr.arr, argc - 1);
	// unsorted = unsorted_lis_filter(lis, arr);
	path = move_unsorted_to_b(&a, &b, arr, lis);
	print_path(path);
	ft_print_stacks(a, b);
	path = extend_path(path, reinsert_sort(&a, &b));


	free(path.arr);
	exit_cleanup(lis, sortedarr, a, arr);
	
}
