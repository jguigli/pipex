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

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		write_usage(ERROR_ARG);
	if (!*envp)
		exit(EXIT_FAILURE);
	pipex.path = find_path(envp);
	pipex.cmd_path = ft_split(pipex.path, ':');
	manage_pipex(pipex, argv, envp);
	free_path(&pipex);
	return (0);
}
