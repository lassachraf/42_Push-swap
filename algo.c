/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:37:13 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/05 10:33:04 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_range(t_stack **a)
{
	int	range;

	range = stack_len(*a);
	if (6 <= range && range <= 16)
		return (3);
	else if (range <= 100)
		return (13);
	else if (range <= 500)
		return (30);
	else
		return (45);
}

void	while_for_norm(t_stack **a, t_stack **b, int *arr, int num)
{
	int	i;
	int	range;

	i = 0;
	range = get_range(a);
	while (*a)
	{
		if (range + i >= num)
			range = num - 1 - i;
		else if ((*a)->value > arr[i] && (*a)->value <= arr[range + i])
		{
			pb(b, a, 1);
			if (stack_len(*b) >= 2 && (*b)->value < (*b)->next->value)
				sb(b, 1);
			i++;
		}
		else if ((*a)->value <= arr[i])
		{
			pb(b, a, 1);
			rb(b, 1);
			i++;
		}
		else
			is_reversed(a);
	}
}

void	sort(t_stack **a, t_stack **b, int num)
{
	int	*arr;

	arr = sort_int_tab(copy_arr(*a), stack_len(*a));
	while_for_norm(a, b, arr, num);
	free(arr);
	while (*b)
		push_max(a, b);
}

void	push_max(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		temp;
	int		nb;
	int		i;

	tmp = *b;
	i = 0;
	nb = tmp->value;
	temp = 0;
	while (tmp)
	{
		if (nb < tmp->value)
		{
			nb = tmp->value;
			temp = i;
		}
		i++;
		tmp = tmp->next;
	}
	max_util(b, temp, stack_len(*b), nb);
	pa(a, b, 1);
}

void	max_util(t_stack **b, int temp, int n, int nb)
{
	if (temp != 0)
	{
		if (temp <= (n / 2))
		{
			while ((*b)->value != nb)
				rb(b, 1);
		}
		else
		{
			while ((*b)->value != nb)
				rrb(b, 1);
		}
	}
}
