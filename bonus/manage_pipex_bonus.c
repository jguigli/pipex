/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:10:41 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/23 18:10:43 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	child_process(t_pipex pipex, char **argv, char **envp)
{
	pipex.cmd_arg = NULL;
	if (pipex.pid_number == 0)
		manage_dup2(pipex, pipex.file1, pipex.pipe[1]);
	else if (pipex.pid_number == pipex.cmd_number - 1)
		manage_dup2(pipex, pipex.pipe[2 * pipex.pid_number - 2],
			pipex.file2);
	else
		manage_dup2(pipex, pipex.pipe[2 * pipex.pid_number - 2],
			pipex.pipe[2 * pipex.pid_number + 1]);
	close_pipes(&pipex);
	pipex.cmd_arg = split_arg(argv[2 + pipex.pid_number]);
	if (check_arg(argv[2 + pipex.pid_number]))
		pipex.cmd_arg = ft_split(argv[2 + pipex.pid_number], 0);
	else
		pipex.cmd_arg = split_arg(argv[2 + pipex.pid_number]);
	if (!pipex.cmd_arg)
		write_error_path(ERROR_CMD_ARG, &pipex);
	pipex.cmd = get_command(pipex.cmd_path, pipex.cmd_arg[0]);
	if (!pipex.cmd)
		write_free_all(ERROR_CMD, &pipex);
	if (execve(pipex.cmd, pipex.cmd_arg, envp) == -1)
		write_free_all(ERROR_EXECV, &pipex);
}

void	manage_pipex(t_pipex pipex, int argc, char **argv, char **envp)
{
	pipex.pid_number = 0;
	pipex.file1 = open(argv[1], O_RDONLY);
	pipex.file2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 644);
	if (pipex.file1 < 0 || pipex.file2 < 0)
		perror(0);
	pipex.pid_number = 0;
	create_pipes(&pipex);
	while (pipex.pid_number < pipex.cmd_number)
	{
		pipex.pid[pipex.pid_number] = fork();
		if (pipex.pid[pipex.pid_number] == -1)
			write_error_path(ERROR_PID, &pipex);
		else if (!pipex.pid[pipex.pid_number])
			child_process(pipex, argv, envp);
		pipex.pid_number++;
	}
	close_pipes(&pipex);
	pipex.pid_number = -1;
	while (++pipex.pid_number < pipex.cmd_number)
		waitpid(pipex.pid[pipex.pid_number], NULL, 0);
}
