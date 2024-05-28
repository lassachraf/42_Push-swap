/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:00:17 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/28 20:52:58 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **head)
{
	int	len;

	len = stack_len(*head);
	if (!*head || !head || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a, int w)
{
	swap(a);
	if (stack_len(*a) != 1 && w == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int w)
{
	swap(b);
	if (stack_len(*b) != 1 && w == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int w)
{
	swap(a);
	swap(b);
	if (stack_len(*a) != 1 && stack_len(*b) != 1 && w == 1)
		write(1, "ss\n", 3);
}
