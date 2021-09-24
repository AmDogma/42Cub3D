/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdewayne <mdewayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:15:48 by mdewayne          #+#    #+#             */
/*   Updated: 2021/04/26 23:17:13 by mdewayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chsize(const char *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] != ch && str[i] != '\0')
		i++;
	return (i);
}

static int	ft_msize(const char *s, char c)
{
	int	add;
	int	i;

	i = 0;
	add = 0;
	while (s[add] != '\0')
	{
		if ((s[add] == c && s[add + 1] != c) || (s[add] != c && add == 0))
			i++;
		add++;
	}
	return (i);
}

static char	**split_dop(char c, char const *s, char **temp)
{
	int		i;
	int		add;

	i = 0;
	add = 0;
	while (s[i] != '\0' && temp)
	{
		if (i == 0 || (s[i - 1] == c && i > 0))
		{
			if (ft_chsize(s + i, c))
			{
				temp[add] = ft_substr(s, i, ft_chsize(s + i, c));
				if (temp[add++] == NULL)
				{
					while (add >= 0)
						free(temp[add--]);
					free (temp);
					return (NULL);
				}
			}
			temp[add] = NULL;
		}
		i++;
	}
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;

	if (s == NULL)
		return (NULL);
	temp = (char **)malloc(sizeof(char *) * (ft_msize(s, c) + 1));
	if (temp)
		temp = split_dop(c, s, temp);
	if (!*s)
		*temp = NULL;
	return (temp);
}
