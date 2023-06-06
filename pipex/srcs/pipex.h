/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:21:49 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 17:03:42 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libftprintf/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

# define CHILD 0
# define READ_END 0
# define WRITE_END 1

////	error.c
void	error_no_errno(char *error, int exitcode);
void	error_cmd_and_exit(char *error);
void	error_and_exit(char *error);

////	parse_argv.c
char	*parse_cmd(char **argv, int command_number, char **env);
char	**parse_cmd_dir(char **env);
char	*parse_cmd_path(char **cmd_dirs, char *command);
char	**parse_parameters(char **argv, int command_number);

////	parse_file.c
void	replace_stdin_with_file1(char *file_path);
void	replace_stdout_with_file2(char *file_path);

#endif
