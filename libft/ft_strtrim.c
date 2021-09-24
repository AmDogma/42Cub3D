/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:15:28 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/26 23:17:50 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dop_trim(int end, const char *s1, const char *set)
{
	int		start;
	int		i;
	char	*temp;

	i = 0;
	start = 0;
	while (set[i] != '\0' && end - start > 0)
	{
		if (s1[start] == set[i])
		{
			start++;
			i = 0;
		}
		else if (s1[end - 1] == set[i])
		{
			end--;
			i = 0;
		}
		else
			i++;
	}
	temp = ft_substr(s1, start, end - start);
	return (temp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		end;

	if (s1 == NULL)
		return (NULL);
	end = (int)ft_strlen(s1);
	dest = dop_trim(end, s1, set);
	return (dest);
}
