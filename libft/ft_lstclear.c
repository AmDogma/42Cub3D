/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:19:47 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/27 23:19:48 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*toclear;

	temp = *lst;
	toclear = temp;
	while (temp)
	{
		temp = temp->next;
		del(toclear->content);
		free(toclear);
		toclear = temp;
	}
	*lst = NULL;
}
