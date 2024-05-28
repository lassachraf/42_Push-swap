/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:06:25 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/28 15:06:22 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min(t_stack **a, t_stack **b, int n)
{
	t_stack	*tmp;
	int		temp;
	int		nb;
	int		i;

	tmp = *a;
	i = 1;
	nb = tmp->value;
	temp = 0;
	while (tmp)
	{
		if (nb > tmp->value)
		{
			nb = tmp->value;
			temp = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (n)
		min_util_four(a, --temp);
	else
		min_util_five(a, --temp, stack_len(*a), nb);
	pb(b, a, 1);
}

void	min_util_four(t_stack **a, int temp)
{
	if (temp != 0)
	{
		if (temp == 1)
		{
			ra(a, 1);
		}
		else if (temp == 2)
		{
			ra(a, 1);
			ra(a, 1);
		}
		else if (temp == 3)
			rra(a, 1);
	}
}

void	min_util_five(t_stack **a, int temp, int n, int nb)
{
	if (temp != 0)
	{
		if (temp <= (n / 2))
		{
			while ((*a)->value != nb)
				ra(a, 1);
		}
		else
			while ((*a)->value != nb)
				rra(a, 1);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	nb;

	nb = stack_len(*a);
	if (nb == 4)
	{
		push_min(a, b, 1);
		sort_three(a);
		pa(a, b, 1);
	}
	if (nb == 5)
	{
		push_min(a, b, 0);
		push_min(a, b, 0);
		sort_three(a);
		pa(a, b, 1);
		pa(a, b, 1);
	}
}
