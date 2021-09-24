/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:15:26 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/26 23:16:57 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	num;

	if (str == NULL)
		return (NULL);
	num = (int)ft_strlen(str + start);
	if (num < len)
		len = num;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (start > (unsigned int)ft_strlen(str) && dest)
		dest[0] = '\0';
	else if (dest)
		ft_strlcpy(dest, str + start, len + 1);
	return (dest);
}
