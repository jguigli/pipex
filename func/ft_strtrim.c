/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:22:38 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/03 17:24:54 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	check_set(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

char	*ft_strtrim(char *s1, char set)
{
	char	*newstr;
	int		i;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && check_set(s1[start], set))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && check_set(s1[end - 1], set))
		end--;
	newstr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (start < end)
	{
		newstr[i++] = s1[start++];
	}
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}
