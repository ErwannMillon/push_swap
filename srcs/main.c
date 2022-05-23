/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/23 15:17:40 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *root)
{
	t_node *current;

	current = root;
	while (current)
	{
		if (current->next && current->num > current->next->num)
			return (-1);
		current = current->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_arr	arr;
	t_arr	sortedarr;
	t_node	*a;
	t_node	*b;
	t_arr	path;
	t_arr	lis;
	
	int 	test[] = {428, 531, 177, 237, 132, 407, 63, 197, 178, 433, 114, 277, 496, 378, 418, 283, 134, 485, 200, 179, 2, 202, 373, 41, 198, 440, 429, 23, 241, 74, 537, 431, 517, 286, 102, 264, 33, 233, 269, 228, 26, 353, 544, 90, 307, 398, 494, 252, 410, 476, 153, 350, 111, 339, 215, 138, 472, 181, 397, 370, 539, 300, 172, 273, 554, 61, 211, 125, 103, 199, 499, 148, 288, 548, 369, 208, 190, 156, 105, 167, 40, 170, 49, 196, 387, 254, 15, 116, 59, 489, 173, 169, 109, 541, 408, 29, 290, 401, 127, 310};
	// char *argv_test[] = {"pushswap", "1", "5", "2", "70", "9", "7", "22", "-100", "4", "23", "61", "8", "33"};
	b = NULL;
	arr = parse_args_to_arr(argc, argv);
	sortedarr.arr = ft_bubble_sort_copy(arr.arr, argc - 1);
	sortedarr.len = argc - 1;
	ft_print_arr(sortedarr.arr, sortedarr.len);
	a = create_list(arr.arr, argc -1, sortedarr);
	ft_print_list(a);
	lis = get_rotating_lis(arr.arr, argc - 1);
	path = move_unsorted_to_b(&a, &b, arr, lis);
	print_path(path);
	ft_print_stacks(a, b);
	path = extend_path(path, reinsert_sort(&a, &b));
	path = extend_path(path, move_min_to_start(&a));
	ft_printf("FINAL:\n");
	ft_print_list(a);
	print_path(path);
	ft_printf("path.len: %d\n", path.len);
	ft_printf("is_sorted: %d\n", is_sorted(a));
	free(path.arr);
	exit_cleanup(lis, sortedarr, a, arr);
}
