/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:10:21 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/23 18:10:22 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_command(char **path, char *cmd)
{
	char	*temp;
	char	*path_cmd;

	if (!cmd)
		return (NULL);
	if (access(cmd, F_OK) == 0 && cmd[0] == '/')
		return (cmd);
	while (*path)
	{
		if (cmd[0] == '/')
			return (NULL);
		temp = ft_strjoin(*path, "/");
		path_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path_cmd, 0) == 0)
			return (path_cmd);
		free(path_cmd);
		path++;
	}
	return (NULL);
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

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
