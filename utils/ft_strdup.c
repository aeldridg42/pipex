/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeldridg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:58:16 by aeldridg          #+#    #+#             */
/*   Updated: 2021/08/01 11:58:22 by aeldridg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	i1;
	char	*ptr;	

	i = ft_strlen(s1);
	i1 = 0;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	while (i--)
		ptr[i1++] = *s1++;
	ptr[i1] = '\0';
	return (ptr);
}
