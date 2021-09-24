/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:15:43 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/26 23:17:08 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		num;

	if (s1 == NULL)
		return (NULL);
	num = (int)(ft_strlen(s1) + ft_strlen(s2)) + 1;
	dest = (char *)malloc(sizeof(char) * num);
	if (dest)
	{
		ft_strlcpy(dest, s1, num);
		ft_strlcat(dest, s2, num);
	}
	return (dest);
}
