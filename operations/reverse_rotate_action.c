/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_action.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:43:32 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/28 16:52:25 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int		len;

	len = stack_len(*stack);
	if (!*stack || !stack || len == 1)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, int w)
{
	reverse_rotate(a);
	if (stack_len(*a) != 1 && w == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int w)
{
	reverse_rotate(b);
	if (stack_len(*b) != 1 && w == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int w)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (stack_len(*a) != 1 && stack_len(*b) != 1 && w == 1)
		write(1, "rrr\n", 4);
}
