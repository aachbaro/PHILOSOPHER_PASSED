/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:37:49 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/15 12:40:05 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	word_count(const char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == sep && str[i])
			i++;
		while (str[i] != sep && str[i])
			i++;
		words++;
	}
	if (str[i - 1] == sep)
		words--;
	return (words);
}

char	**mall_tab(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	k = 0;
	i = 0;
	tab = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (k < (word_count(s, c)))
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		tab[k] = malloc(sizeof(char) * (j - i + 1));
		if (!tab[k])
			return (NULL);
		i = j;
		k++;
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	int		k;
	int		i;
	int		j;
	char	**tab;

	k = 0;
	i = 0;
	tab = mall_tab(s, c);
	if (!tab)
		return (NULL);
	while (k < word_count(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i] != c && s[i])
			tab[k][j++] = s[i++];
		tab[k++][j] = 0;
	}
	tab[k] = NULL;
	return (tab);
}
