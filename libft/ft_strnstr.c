/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:15:32 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/26 23:17:01 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	if (!str2[0])
		return ((char *)str1);
	while (str1[i1] != '\0' && n > i1)
	{
		i2 = 0;
		while (str1[i1 + i2] == str2[i2] && n > i1 + i2)
		{
			i2++;
			if (str2[i2] == '\0')
				return ((char *)str1 + i1);
		}
		i1++;
	}
	return (NULL);
}
