/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:10:52 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/23 18:10:53 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		write_usage(ERROR_ARG);
	if (!*envp)
		exit(EXIT_FAILURE);
	pipex.cmd_number = argc - 3;
	pipex.pipe_number = 2 * (pipex.cmd_number - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_number);
	if (!pipex.pipe)
		write_error(ERROR_PIPEALLOC);
	pipex.pid = (pid_t *)malloc(sizeof(pid_t) * pipex.cmd_number);
	if (!pipex.pid)
	{
		free(pipex.pipe);
		write_error(ERROR_PIDALLOC);
	}
	pipex.path = find_path(envp);
	pipex.cmd_path = ft_split(pipex.path, ':');
	manage_pipex(pipex, argc, argv, envp);
	free_path(&pipex);
	return (0);
}
