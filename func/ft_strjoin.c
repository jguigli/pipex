/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:36:48 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/02 18:10:24 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

static int	ft_length_total(char *s1, char *s2)
{
	int	length;

	length = ft_strlen(s1) + ft_strlen(s2);
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cat;
	int		length;

	if (!s1 || !s2)
		return (NULL);
	length = ft_length_total(s1, s2);
	cat = (char *)malloc(sizeof(char) * length + 1);
	if (!cat)
		return (NULL);
	cat[0] = '\0';
	cat = ft_strcat(cat, s1);
	cat = ft_strcat(cat, s2);
	cat[length] = '\0';
	return (cat);
}
