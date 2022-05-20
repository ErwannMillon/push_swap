/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:49:05 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/20 15:35:22 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_node *root)
{
	t_node	*tmp;

	while (root)
	{
		tmp = (root)->next;
		free(root);
		root = tmp;
	}
}

void	free_lis_vars(const int **len_and_prev, int *max_and_addindex)
{
	free((void *)len_and_prev[0]);
	free((void *)len_and_prev[1]);
	free((void *)len_and_prev);
	free((void *)max_and_addindex);
}

void	exit_cleanup(t_arr lis, t_arr sortedarr, t_node *a, t_arr arr)
{
	free(lis.arr);
	free(sortedarr.arr);
	ft_free_list(a);
	free(arr.arr);
}
