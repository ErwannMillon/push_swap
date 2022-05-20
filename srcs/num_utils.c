/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:24:09 by gmillon           #+#    #+#             */
/*   Updated: 2022/05/20 16:39:24 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_arr	extend_path(t_arr arr, t_arr extension)
{
	t_arr	newpath;

	newpath.arr = malloc((arr.len + extension.len + 2) * sizeof(int));
	ft_memcpy(newpath.arr, arr.arr, arr.len * sizeof(int));
	ft_memcpy(newpath.arr + arr.len, extension.arr, extension.len * sizeof(int));
	free(arr.arr);
	free(extension.arr);
	return (newpath);
}

