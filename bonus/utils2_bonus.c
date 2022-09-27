/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:05:45 by jguigli           #+#    #+#             */
/*   Updated: 2022/04/15 17:05:46 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static int	count_quote(char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[++i])
	{
		if (argv[i] == 39)
			count++;
	}
	return (count);
}

char	**split_arg(char *argv)
{
	int		count;
	char	**tab;

	count = count_quote(argv);
	if (count == 2)
		tab = ft_split_cmd_quote(argv);
	else
		tab = ft_split(argv, ' ');
	return (tab);
}

int	check_arg(char *argv)
{
	int	i;
	int	count;
	int	final;

	i = 0;
	count = 0;
	final = ft_strlen(argv);
	if (argv[0] == ' ' || argv[final - 1] == ' ')
		return (1);
	while (argv[i])
	{
		if (ft_isalpha(argv[i]))
		{
			count++;
			while (ft_isalpha(argv[i + 1]))
				i++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}
