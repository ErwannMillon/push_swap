/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:07:14 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/25 19:38:32 by gmillon          ###   ########.fr       */
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
	new->sorted_index = ft_get_arr_index(num, sortedarr.arr, sortedarr.len);
	if (new->sorted_index == 0)
		new->previous_in_sorted = sortedarr.len - 1;
	else
		new->previous_in_sorted = sortedarr.arr[new->sorted_index - 1];
	new->next_sorted = \
	sortedarr.arr[(new->sorted_index + 1) % sortedarr.len];
	new->next = NULL;
	if (DEBUG)
		ft_printf("i %d num %d\n", new->num, new->next_sorted);
	return (new);
}

t_node	*create_list(int *a, int len, t_arr sortedarr)
{
	int		i;
	t_node	*first;
	t_node	*current;

	first = create_node(a[0], sortedarr);
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

static void	free_inc_split(char **arr)
{
	int	i;

	i = 1;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	check_str_arg(int *argc, char ***argv)
{
	if (*argc == 2 && ft_strchr((*argv)[1], ' '))
	{
		(*argv) = str_arg_split((*argv)[1], ' ');
		*argc = arr_len((*argv) + 1) + 1;
		return (1);
	}
	return (0);
}

t_arr	parse_args_to_arr(int argc, char **argv)
{
	int		i;
	int		*arr;
	t_arr	array;
	int		should_free;

	arr = malloc(argc * sizeof(int));
	i = 0;
	if (argc < 2)
		exit(1);
	should_free = check_str_arg(&argc, &argv);
	while (i < argc - 1)
	{
		check_if_int(argv[i + 1]);
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	array.arr = arr;
	array.len = argc - 1;
	if (should_free)
		free_inc_split(argv);
	check_if_dup(array);
	return (array);
}
