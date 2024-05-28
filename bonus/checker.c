/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:11:35 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/06 16:32:31 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42_libft/libft.h"
#include "../push_swap.h"
#include "get_next_line.h"

void	ft_free_error(t_stack *a, t_stack *b, char *line)
{
	free(line);
	free_stack(&a, &b);
	get_next_line(42);
	ft_error();
}	

int	ft_check_operation(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(b, a, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, 0);
	else
		return (ft_free_error(*a, *b, line), 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	stack_init(&a, argv + 1, argc);
	size = stack_len(a);
	line = get_next_line(0);
	while (line)
	{
		ft_check_operation(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (!stack_sorted(a) || size != stack_len(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(&a, &b);
	return (0);
}
