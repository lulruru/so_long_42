/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:57:54 by rencarna          #+#    #+#             */
/*   Updated: 2023/05/04 11:35:19 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	checksep(const char s, char c)
{
	if (c == s)
		return (1);
	return (0);
}

static int	wordcount(const char *s, char c)
{
	int	compteur;

	compteur = 0;
	while (*s)
	{
		while (*s && checksep(*s, c))
			s++;
		if (*s)
			compteur++;
		while (*s && !checksep(*s, c))
			s++;
	}
	return (compteur);
}

static char	**ft_freee(char **s, int j)
{
	while (j >= 0)
	{
		free(s[j]);
		j--;
	}
	free(s);
	return (NULL);
}

static char	*makeword(const char *s, char c)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	word = malloc(sizeof(*word) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (*s && !checksep(*s, c))
		word[i++] = *(s++);
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**new;
	int		i;

	new = ft_calloc((wordcount(s, c) + 1), sizeof(*new));
	if (!new)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && checksep(*s, c))
			s++;
		if (*s)
		{
			new[i] = makeword(s, c);
			if (!new[i++])
				return (ft_freee(new, i));
		}
		while (*s && !checksep(*s, c))
			s++;
	}
	return (new);
}
