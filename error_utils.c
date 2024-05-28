/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:48:41 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/06 12:00:28 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_error_args(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i++]);
	}
	free(s);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_stack_error(t_stack *a)
{
	t_stack	*current;
	t_stack	*next;

	current = a;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
