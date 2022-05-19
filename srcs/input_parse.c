/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/19 18:19:52 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int num, t_arr sortedarr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->num = num;
	new->sorted_index = ft_get_list_index(num, sortedarr.arr, sortedarr.len);
	if (new->sorted_index == 0)
		new->previous_in_sorted = sortedarr.len - 1;
	else
		new->previous_in_sorted = sortedarr.arr[new->sorted_index - 1];
	new->next_in_sorted = sortedarr.arr[(new->sorted_index + 1) % sortedarr.len];
	new->next = NULL;
	ft_printf("i %d num %d\n", new->num, new->next_in_sorted);
	return (new);
}

t_node	*create_list(int *a, int len, t_arr sortedarr)
{
	int		i;
	t_node	**root;
	t_node	*first;
	t_node	*current;

	first = create_node(a[0], sortedarr);
	root = &first;
	current = first;
	i = 1;
	while (i < len)
	{
		current->next = create_node(a[i], sortedarr);
		current = current->next;
		i++;
	}
	return (first);
}

int	parse_args(int argc, char **argv)
{
	int		i;
	int		*a;
	t_arr	sortedarr;
	t_node	*root;
	t_node	*b;

	b = malloc(sizeof(int) * argc);
	a = malloc(argc * sizeof(int));
	i = 0;
	while (i < argc - 1)
	{
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	sortedarr.arr = ft_bubble_sort_copy(a, argc - 1);
	sortedarr.len = argc - 1;
	root = create_list(a, argc -1, sortedarr);

	ft_print_list(root);
	s(&root);
	ft_print_list(root);
	// ft_print_list(root);
	p(&root, &b);
	// ft_printf("\n");
	ft_print_list(root);
	ft_print_list(b);

	// ft_print_arr(sortedarr.arr, argc - 1, 0);
	// ft_printf("\n");
	// ft_bubble_sort(sortedarr, argc - 1);
	// ft_print_arr(sortedarr, argc - 1, 0);
	return(0);
}