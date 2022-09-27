/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:36:42 by jguigli           #+#    #+#             */
/*   Updated: 2022/04/04 16:36:43 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	write_error_path(char *str, t_pipex *pipex)
{
	write(2, str, ft_strlen(str));
	free_path(pipex);
	exit(EXIT_FAILURE);
}

void	write_free_all(char *str, t_pipex *pipex)
{
	write(2, str, ft_strlen(str));
	free_all(pipex);
	exit(EXIT_FAILURE);
}

void	write_error_cmd(char *str, t_pipex *pipex)
{
	write(2, str, ft_strlen(str));
	free_all(pipex);
	exit(127);
}

void	write_usage(char *str)
{
	write(2, USAGE, ft_strlen(USAGE));
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
