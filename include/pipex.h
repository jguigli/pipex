/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:11:26 by jguigli           #+#    #+#             */
/*   Updated: 2022/03/23 18:11:27 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

# define ERROR_FILE "Error while opening the file\n"
# define ERROR_PIPE "Pipe has failed\n"
# define ERROR_PID "Error while creating child process\n"
# define ERROR_EXECV "Error while executing the command\n"
# define ERROR_DUP "Error while duplicating the fd\n"
# define ERROR_CMD "Command not found\n"
# define ERROR_CMD_ARG "Incorrect arguments\n"
# define ERROR_ARG "Incorrect number of arguments\n"
# define USAGE "Usage : ./pipex infile cmd1 cmd2 outfile\n"
# define ENVP "Empty environnement\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	int		file1;
	int		file2;
	char	*path;
	char	**cmd_path;
	char	**cmd_arg;
	char	*cmd;
}	t_pipex;

void	manage_pipex(t_pipex pipex, char **argv, char **envp);
void	child_process(t_pipex pipex, char **argv, char **envp);
void	child_process2(t_pipex pipex, char **argv, char **envp);
char	*get_command(char **path, char *cmd);
char	*find_path(char **envp);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *first, const char *second, size_t length);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strtrim(char *s1, char set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isalpha(int c);
char	*find_path(char **envp);
void	write_error(char *str);
void	write_error_path(char *str, t_pipex *pipex);
void	write_free_all(char *str, t_pipex *pipex);
void	write_usage(char *str);
void	write_error_cmd(char *str, t_pipex *pipex);
void	free_path(t_pipex *pipex);
void	free_arg(t_pipex *pipex);
void	free_all(t_pipex *pipex);
char	**split_arg(char *argv);
int		check_arg(char *argv);
char	**ft_split_cmd_quote(char *str);

#endif
