/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmillon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:11:02 by gmillon           #+#    #+#             */
/*   Updated: 2022/09/16 15:53:25 by gmillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_node *a)
{
    while (a->next)
    {
        if (a->num > a->next->num) 
            return (0);
        a = a->next;
    }
    return (1);
}

t_arr add_input_to_path(t_arr path, char *input)
{
    t_arr       input_arr;
    const char  *operations[11] = {"pa\n", "pb\n", "sa\n", "sb\n", \
                                    "ss\n", "rr\n", "ra\n", "rb\n", "rra\n", "rrb\n", "rrr\n"};
    int         i;

    input_arr.arr = malloc((sizeof(int) * 1));
    input_arr.arr[0] = -1;
    input_arr.len = 1;
    i = 0;
    while (i < 11) 
    {
        if (!ft_strncmp(input, operations[i], ft_strlen(operations[i]) + 1))
        {
            input_arr.arr[0] = i + 1;
            if (DEBUG)
                ft_printf("operation %d\n", i + 1);
            return (extend_path(path, input_arr));
        }
        i++;
    }
    ft_putstr_fd("Error\n", 2);
    exit(1);
}
void double_call(t_node **a, t_node **b, int operation)
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

void list_cleanup(t_arr path, t_node **a, t_node **b)
{
    if (!b && is_sorted(*a))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    if (a && *a)
        ft_free_list(*a);
    if (b && *b)
        ft_free_list(*b);
    free(path.arr);
}

void execute_path(t_arr path, t_node **a)
{
    t_node  *b;
    const t_node  **stacks[2] = {&b, a};
    int     i;

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
            s(stacks[path.arr[i] % 2]);
        else if (path.arr[i] == RA || path.arr[i] == RB)
            r(stacks[path.arr[i] % 2]);
        else if (path.arr[i] == RRA || path.arr[i] == RRB) 
            rr(stacks[path.arr[i] % 2]);
        i++;
        ft_print_stacks(*a, b);
    }
    list_cleanup(path, a, &b);
}
int main(int argc, char **argv)
{
    t_arr   arr;
    const t_arr   sortedarr = {ft_bubble_sort_copy(arr.arr, argc - 1), argc - 1};
    t_node  *a;
    t_arr   path;
    char    *input;

    arr = parse_args_to_arr(argc, argv);
	a = create_list(arr.arr, argc -1, sortedarr);
    input = get_next_line(0);
    while (input[0] != '\n')
    {
        path = add_input_to_path(path, input);
        free(input);
        input = get_next_line(0);
    }
     
    print_path(path);
    execute_path(path, &a);
    free(input);
    free(sortedarr.arr);
    free(arr.arr);
    return (0);

}