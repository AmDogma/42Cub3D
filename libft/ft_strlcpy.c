/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:15:39 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/26 23:17:06 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *cpy, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL)
		return (0);
	else if (n != 0)
		dest[0] = '\0';
	while (cpy[i] != '\0' && cpy + i)
	{
		if (n > i + 1)
		{
			dest[i] = cpy[i];
			dest[i + 1] = '\0';
		}
		i++;
	}
	return (i);
}
