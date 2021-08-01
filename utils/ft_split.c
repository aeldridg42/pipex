/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <aeldridg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:00:17 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/01 17:09:17 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	wordcount(char const *s, char c)
{
	int	ctr;
	int	i;
	int	check;

	i = 0;
	ctr = 0;
	while (s[i])
	{
		check = 0;
		while (s[i] != c && s[i])
		{
			++check;
			++i;
		}
		if ((s[i] == c || !s[i]) && check)
			++ctr;
		if (s[i] == '\0')
			break ;
		++i;
	}
	return (ctr);
}

static int	symbcount(char const *s, char c, int ptr)
{
	int	ctr;

	ctr = 0;
	while (s[ptr] != c && s[ptr])
	{
		++ctr;
		++ptr;
	}
	return (ctr);
}

static void	*ft_free(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		++i;
	}
	free(split);
	return (NULL);
}

static char	**ft_put(char const *s, char c, char **split, int words)
{
	int	wordctr;
	int	ptr;
	int	length;
	int	i;

	ptr = 0;
	wordctr = 0;
	while (wordctr < words)
	{
		while (s[ptr] == c)
			++ptr;
		length = symbcount(s, c, ptr);
		split[wordctr] = (char *)malloc(sizeof(char) * (length + 1));
		if (!split[wordctr])
			return (ft_free(split, words));
		i = 0;
		while (s[ptr] != c && s[ptr])
			split[wordctr][i++] = s[ptr++];
		split[wordctr++][i] = '\0';
	}
	split[wordctr] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;

	if (!s)
		return (NULL);
	words = wordcount(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split = ft_put(s, c, split, words);
	return (split);
}
