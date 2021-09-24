/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:20:20 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/27 23:20:23 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	new = NULL;
	if (lst)
		new = ft_lstnew(f(lst->content));
	temp = new;
	while (new && lst && lst->next)
	{
		temp->next = ft_lstnew(f(lst->next->content));
		lst = lst->next;
		if (temp->next == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		temp = temp->next;
	}
	return (new);
}
