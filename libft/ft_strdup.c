/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:15:45 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/26 23:17:09 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		num;

	num = (int)ft_strlen(str) + 1;
	dest = (char *)malloc(sizeof(char) * num);
	if (dest)
		ft_strlcpy(dest, str, num);
	return (dest);
}
