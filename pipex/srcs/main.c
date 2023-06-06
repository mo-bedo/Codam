/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:06:52 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/30 13:43:22 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipex_child1(int *pipe_fd, char **argv, char **env)
{
	char	*cmd;
	char	**parameters;

	if (close(pipe_fd[READ_END]) == -1)
		error_and_exit("close");
	if (dup2(pipe_fd[WRITE_END], STDOUT_FILENO) == -1)
		error_and_exit("dup2");
	parameters = parse_parameters(argv, 0);
	replace_stdin_with_file1(argv[1]);
	cmd = parse_cmd(argv, 0, env);
	if (!cmd)
		error_no_errno("permission denied\n", 126);
	execve(cmd, parameters, env);
}

static void	pipex_child2(int *pipe_fd, char **argv, char **env)
{
	char	*cmd;
	char	**parameters;

	if (close(pipe_fd[WRITE_END]) == -1)
		error_and_exit("close");
	if (dup2(pipe_fd[READ_END], STDIN_FILENO) == -1)
		error_and_exit("dup2");
	parameters = parse_parameters(argv, 1);
	replace_stdout_with_file2(argv[4]);
	cmd = parse_cmd(argv, 1, env);
	if (!cmd)
		error_no_errno("permission denied:\n", 126);
	execve(cmd, parameters, env);
}

static pid_t	fork_wrap(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_and_exit("fork");
	return (pid);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	child1;
	pid_t	child2;
	int		wstatus2;

	if (argc != 5)
	{
		ft_printf("Invalid number of arguments.\n");
		exit(1);
	}
	if (pipe(pipe_fd) == -1)
		error_and_exit("pipe");
	child1 = fork_wrap();
	if (child1 == CHILD)
		pipex_child1(pipe_fd, argv, env);
	child2 = fork_wrap();
	if (child2 == CHILD)
		pipex_child2(pipe_fd, argv, env);
	close(pipe_fd[WRITE_END]);
	close(pipe_fd[READ_END]);
	waitpid(child1, NULL, 0);
	waitpid(child2, &wstatus2, 0);
	if (WIFEXITED(wstatus2))
		return (WEXITSTATUS(wstatus2));
	return (0);
}
