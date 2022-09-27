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

#include "../include/pipex_bonus.h"

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

void	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_number - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			write_error(ERROR_PIPE);
		i++;
	}
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_number)
	{
		close(pipex->pipe[i]);
		i++;
	}
}

void	manage_dup2(t_pipex pipex, int first, int second)
{
	if (dup2(first, STDIN_FILENO) < 0)
	{
		free_path(&pipex);
		write_error(ERROR_DUP);
	}
	if (dup2(second, STDOUT_FILENO) < 0)
	{
		free_path(&pipex);
		write_error(ERROR_DUP);
	}
}
