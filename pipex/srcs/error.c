/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:48:25 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/30 13:29:10 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_no_errno(char *error, int exitcode)
{
	ft_putstr_fd(error, 2);
	exit(exitcode);
}

void	error_cmd_and_exit(char *error)
{
	write(2, error, ft_strlen(error));
	ft_putstr_fd(": command not found \n", 2);
	free(error);
	exit(127);
}

void	error_and_exit(char *error)
{
	ft_putstr_fd(error, 2);
	perror(" ");
	exit(errno);
}
