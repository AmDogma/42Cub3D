/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:14:49 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/26 23:15:01 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nsize(int n)
{
	int	i;

	i = 0;
	if (n < 0 || !n)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*dest;

	i = ft_nsize(n);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest)
	{
		if (n < 0)
			dest[0] = '-';
		else if (!n)
			dest[0] = '0';
		dest[i--] = '\0';
		while (n != 0)
		{
			if (n > 0)
				dest[i] = n % 10 + 48;
			else
				dest[i] = -(n % 10) + 48;
			n /= 10;
			i--;
		}
	}
	return (dest);
}
