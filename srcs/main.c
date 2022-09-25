/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/25 18:21:30 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *root)
{
	t_node	*current;

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

	b = NULL;
	arr = parse_args_to_arr(argc, argv);
	sortedarr.arr = ft_bubble_sort_copy(arr.arr, argc - 1);
	sortedarr.len = argc - 1;
	a = create_list(arr.arr, argc - 1, sortedarr);
	path = move_unsorted_to_b(&a, &b, arr, get_rotating_lis(arr.arr, argc - 1));
	path = extend_path(path, reinsert_sort(&a, &b));
	path = extend_path(path, move_min_to_start(&a));
	print_path_output(path);
	free(path.arr);
	exit_cleanup(sortedarr, a, arr);
}
