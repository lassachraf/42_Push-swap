/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:08:45 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/14 19:20:40 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*ret_list;
	void	*content;

	ret_list = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			content = f(lst->content);
			new_list = ft_lstnew(content);
			if (!new_list)
			{
				del(content);
				ft_lstclear(&ret_list, del);
				return (ret_list);
			}
			ft_lstadd_back(&ret_list, new_list);
			lst = lst->next;
		}
	}
	return (ret_list);
}
