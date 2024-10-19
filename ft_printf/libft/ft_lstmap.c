/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:30:32 by vcornill          #+#    #+#             */
/*   Updated: 2023/10/19 19:30:05 by vcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newnode;
	t_list	*newtail;
	void	*newcontent;

	new = 0;
	while (lst)
	{
		newcontent = f(lst->content);
		newnode = ft_lstnew(newcontent);
		if (!newnode && del)
		{
			del(newcontent);
			ft_lstclear(&new, del);
			return (NULL);
		}
		if (!new)
			new = newnode;
		else
			newtail->next = newnode;
		newtail = newnode;
		lst = lst->next;
	}
	return (new);
}
