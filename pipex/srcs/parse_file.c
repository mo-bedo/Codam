/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:04:31 by jbedaux	       #+#    #+#             */
/*   Updated: 2022/01/25 16:47:20 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	replace_stdin_with_file1(char *file_path)
{
	int	file;

	if (access(file_path, R_OK) == -1)
		error_and_exit(file_path);
	file = open(file_path, O_RDONLY);
	if (file == -1)
		error_and_exit("open error");
	if (dup2(file, STDIN_FILENO) == -1)
		error_and_exit("dup2");
}

void	replace_stdout_with_file2(char *file_path)
{
	int	file;

	file = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (file == -1)
		error_and_exit(file_path);
	if (dup2(file, STDOUT_FILENO) == -1)
		error_and_exit("dup2");
}
