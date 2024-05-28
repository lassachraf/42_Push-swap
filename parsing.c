/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:00:04 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/29 19:07:02 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] && (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (res * 10 > INT_MAX || res * 10 * sign < INT_MIN)
			return (2147483648);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res *= sign);
}

void	ft_check_int(char **s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!s[0])
		ft_error_args(s);
	while (s[i])
	{
		if (ft_atol(s[i]) > 2147483647 || ft_atol(s[i]) < -2147483648)
			flag = 1;
		else if ((s[i][0] == '-' || s[i][0] == '+') && !s[i][1])
			flag = 1;
		i++;
	}
	if (flag == 1)
		ft_error_args(s);
}

void	ft_double_free(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	ft_check_args(int ac, char **av)
{
	char	**s;
	int		i;
	int		j;
	int		k;

	i = 1;
	while (i < ac)
	{
		j = 0;
		s = ft_split(av[i], ' ');
		ft_check_int(s);
		while (s[j])
		{
			k = 0;
			if (s[j][k] == '-' || s[j][k] == '+')
				k = 1;
			while (s[j][k])
				if (!ft_isdigit(s[j][k++]))
					ft_error_args(s);
			j++;
		}
		ft_double_free(s);
		i++;
	}
}

void	ft_check_doubles(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*hold;

	tmp = a;
	hold = a;
	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
			{
				ft_stack_error(hold);
				ft_error();
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
}
