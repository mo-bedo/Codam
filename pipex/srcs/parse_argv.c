/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:04:35 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/30 13:29:54 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_all(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*parse_cmd(char **argv, int command_number, char **env)
{
	char	*cmd;
	char	**temp_array_cmd;
	char	**cmd_dir;

	cmd_dir = parse_cmd_dir(env);
	temp_array_cmd = ft_split(argv[2 + command_number], ' ');
	cmd = temp_array_cmd[0];
	cmd = parse_cmd_path(cmd_dir, cmd);
	free_all(temp_array_cmd);
	free_all(cmd_dir);
	return (cmd);
}

// Returns all the cmd directories from the environment. 
// Returns NULL if no directories are found or env is empty.
char	**parse_cmd_dir(char **env)
{
	char	**cmd_dir;
	char	*temp;
	int		i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 6))
		{
			temp = ft_substr(env[i], 5, ft_strlen(env[i]));
			cmd_dir = ft_split(temp, ':');
			free(temp);
			return (cmd_dir);
		}
		i++;
	}
	return (NULL);
}

//	Returns first occurence of command in one of the cmd_dirs.
//	Returns NULL if no occurence of command is found
char	*parse_cmd_path(char **cmd_dirs, char *command)
{
	char	*command_path;
	int		i;

	i = 0;
	if (!access(command, X_OK))
	{
		command_path = ft_strdup(command);
		return (command_path);
	}
	command = ft_strjoin("/", command);
	if (!cmd_dirs || !command)
		return (NULL);
	while (cmd_dirs[i])
	{
		command_path = ft_strjoin(cmd_dirs[i], command);
		if (!access(command_path, X_OK))
			return (command_path);
		free(command_path);
		i++;
	}
	command = ft_strtrim(command, "/");
	error_cmd_and_exit(command);
	return (NULL);
}

char	**parse_parameters(char **argv, int command_number)
{
	char	**parameters;

	parameters = ft_split(argv[2 + command_number], ' ');
	return (parameters);
}
