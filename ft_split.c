/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:59:34 by picatrai          #+#    #+#             */
/*   Updated: 2023/11/12 10:32:14 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mega_malloc(char const *s, char c)
{
	size_t	i;
	size_t	compteur;

	i = 0;
	compteur = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			compteur++;
		i++;
	}
	return (compteur);
}

static int	mini_malloc(char const *s, char c, size_t i)
{
	size_t	compteur;

	compteur = 0;
	while (s[i] && s[i] != c)
	{
		compteur++;
		i++;
	}
	return (compteur);
}

char	*ft_gain_de_place(const char *s, char c, size_t i)
{
	size_t	k;
	char	*str;

	str = malloc((mini_malloc(s, c, i) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	k = 0;
	while (s[i + k] != c && s[i + k] != '\0')
	{
		str[k] = s[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	new;

	split = malloc ((mega_malloc(s, c) + 1) * sizeof(char *));
	if (split == NULL || s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	new = 1;
	while (s[i])
	{
		if (new == 1 && s[i] != c)
		{
			split[j] = ft_gain_de_place(s, c, i);
			j++;
			new = 0;
		}
		if (new == 0 && s[i] == c && s[i + 1] != c)
			new = 1;
		i++;
	}
	split[j] = 0;
	return (split);
}
