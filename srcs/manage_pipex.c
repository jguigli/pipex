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

#include "../include/pipex.h"

void	child_process(t_pipex pipex, char **argv, char **envp)
{
	if (dup2(pipex.file1, STDIN_FILENO) < 0)
		write_error_path(ERROR_DUP, &pipex);
	close(pipex.pipe[0]);
	if (dup2(pipex.pipe[1], STDOUT_FILENO) < 0)
		write_error_path(ERROR_DUP, &pipex);
	if (check_arg(argv[2]))
		pipex.cmd_arg = ft_split(argv[2], 0);
	else
		pipex.cmd_arg = split_arg(argv[2]);
	if (!pipex.cmd_arg)
		write_error_path(ERROR_CMD_ARG, &pipex);
	pipex.cmd = get_command(pipex.cmd_path, pipex.cmd_arg[0]);
	if (!pipex.cmd)
		write_error_cmd(ERROR_CMD, &pipex);
	if (execve(pipex.cmd, pipex.cmd_arg, envp) == -1)
		write_free_all(ERROR_EXECV, &pipex);
}

void	child_process2(t_pipex pipex, char **argv, char **envp)
{
	if (dup2(pipex.pipe[0], STDIN_FILENO) < 0)
		write_error_path(ERROR_DUP, &pipex);
	close(pipex.pipe[1]);
	if (dup2(pipex.file2, STDOUT_FILENO) < 0)
		write_error_path(ERROR_DUP, &pipex);
	if (check_arg(argv[3]))
		pipex.cmd_arg = ft_split(argv[3], 0);
	else
		pipex.cmd_arg = split_arg(argv[3]);
	if (!pipex.cmd_arg)
		write_error_path(ERROR_CMD_ARG, &pipex);
	pipex.cmd = get_command(pipex.cmd_path, pipex.cmd_arg[0]);
	if (!pipex.cmd)
		write_error_cmd(ERROR_CMD, &pipex);
	if (execve(pipex.cmd, pipex.cmd_arg, envp) == -1)
		write_free_all(ERROR_EXECV, &pipex);
}

void	manage_pipex(t_pipex pipex, char **argv, char **envp)
{
	pipex.file1 = open(argv[1], O_RDONLY);
	pipex.file2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 000644);
	if (pipex.file1 < 0 || pipex.file2 < 0)
		perror(0);
	if (pipe(pipex.pipe) < 0)
		write_error_path(ERROR_PIPE, &pipex);
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		write_error_path(ERROR_PID, &pipex);
	else if (pipex.pid1 == 0)
		child_process(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		write_error_path(ERROR_PID, &pipex);
	else if (pipex.pid2 == 0)
		child_process2(pipex, argv, envp);
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}
