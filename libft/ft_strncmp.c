/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:15:33 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/26 23:17:03 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *cmp1, const char *cmp2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (n > i && !diff && (cmp1[i] != '\0' || cmp2[i] != '\0'))
	{
		diff = *((unsigned char *)cmp1 + i) - *((unsigned char *)cmp2 + i);
		i++;
	}
	return (diff);
}
