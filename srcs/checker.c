/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:11:02 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/19 19:38:29 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_call(t_node **a, t_node **b, int operation)
{
	if (operation == SS)
	{
		s(a);
		s(b);
	}
	if (operation == RRR)
	{
		rr(a);
		rr(b);
	}
	if (operation == RR)
	{
		r(a);
		r(b);
	}
}

void	list_cleanup(t_arr path, t_node **a, t_node **b)
{
	if ((!b || !(*b)) && is_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (a && *a)
		ft_free_list(*a);
	if (b && *b)
		ft_free_list(*b);
	free(path.arr);
}

void	execute_path(t_arr path, t_node **a)
{
	t_node			*b;
	const t_node	**stacks[2] = {&b, a};
	int				i;

	(t_node **)stacks;
	i = 0;
	b = NULL;
	while (i < path.len)
	{
		if (path.arr[i] == SS || path.arr[i] == RR || path.arr[i] == RRR)
			double_call(a, &b, path.arr[i]);
		else if (path.arr[i] == PA)
			p(&b, a);
		else if (path.arr[i] == PB)
			p(a, &b);
		else if (path.arr[i] == SA || path.arr[i] == SB)
			s((t_node **)stacks[path.arr[i] % 2]);
		else if (path.arr[i] == RA || path.arr[i] == RB)
			r((t_node **)stacks[path.arr[i] % 2]);
		else if (path.arr[i] == RRA || path.arr[i] == RRB)
			rr((t_node **)stacks[path.arr[i] % 2]);
		i++;
	}
	list_cleanup(path, a, &b);
}

int	main(int argc, char **argv)
{
	t_arr		arr;
	const t_arr	sortedarr = {ft_bubble_sort_copy(arr.arr, argc - 1), argc - 1};
	t_node		*a;
	t_arr		path;
	char		*input;

	arr = parse_args_to_arr(argc, argv);
	a = create_list(arr.arr, argc -1, sortedarr);
	input = get_next_line(0);
	while (input[0] != '\n')
	{
		path = add_input_to_path(path, input);
		free(input);
		input = get_next_line(0);
	}
	execute_path(path, &a);
	free(input);
	free(sortedarr.arr);
	free(arr.arr);
	return (0);
}
