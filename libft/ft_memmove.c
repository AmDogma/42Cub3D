/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:16:16 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/26 23:17:21 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *cpy, size_t n)
{
	size_t	count;

	count = 0;
	if (dest > cpy)
	{
		while (count < n && (dest || cpy))
		{
			*((unsigned char *)dest + n - 1) = *((unsigned char *)cpy + n - 1);
			n--;
		}
	}
	else
	{
		while (count < n && (dest || cpy))
		{
			*((unsigned char *)dest + count) = *((unsigned char *)cpy + count);
			count++;
		}
	}
	return (dest);
}
