/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:26:43 by jguigli           #+#    #+#             */
/*   Updated: 2022/04/19 17:26:46 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	count_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i++])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			count++;
		}
		if (str[i] == 39)
		{
			while (str[++i] != 39)
				;
			if (str[i + 1] != ' ')
			{
				while (str[i] != ' ' && str[i])
					i++;
			}
		}
	}
	return (count);
}

static void	ft_split_cmd_quote2(char *str, char **tab, int *i, int *p)
{
	int	j;

	j = *i;
	while (str[*i] != ' ' && str[*i] != 39 && str[*i])
		(*i)++;
	if (*i > j)
		tab[(*p)++] = ft_substr(str, j, *i - j);
	if (str[*i] == 39)
	{
		j = ++(*i);
		while (str[*i] != 39)
			(*i)++;
		if (str[*i + 1] != ' ' && str[*i + 1])
		{
			while (str[*i] != ' ' && str[*i])
				(*i)++;
		}
		tab[(*p)++] = ft_substr(str, j, *i - j);
	}
}

char	**ft_split_cmd_quote(char *str)
{
	int		i;
	int		p;
	int		count;
	char	**tab;

	i = 0;
	p = 0;
	count = count_word(str);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	if (count == 1)
		tab[p++] = ft_substr(str, i, ft_strlen(str));
	else
	{
		while (str[i])
		{
			ft_split_cmd_quote2(str, tab, &i, &p);
			if (str[i] == '\0')
				break ;
			i++;
		}
	}
	tab[p] = '\0';
	return (tab);
}
