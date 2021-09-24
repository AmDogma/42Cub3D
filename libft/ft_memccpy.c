/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:14:52 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/26 23:15:00 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *cpy, int ch, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)cpy + i);
		if (*((unsigned char *)cpy + i) == (unsigned char)ch)
			return (((unsigned char *)dest + i + 1));
		i++;
	}
	return (NULL);
}
