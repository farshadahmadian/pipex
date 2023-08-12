/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:51:39 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/10 17:59:34 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_env_var(const char *var, char **env)
{
	int		i;
	char	*env_var;

	i = 0;
	env_var = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], var, ft_strlen(var)))
		{
			env_var = env[i];
			break ;
		}
		i++;
	}
	return (env_var);
}

char	*get_env_var_value(char *env_var)
{
	char	*env_var_value;

	env_var_value = ft_strchr(env_var, '=') + 1;
	return (env_var_value);
}

char	**get_paths(char *env_var_value)
{
	char	**paths;

	paths = ft_split(env_var_value, ':');
	return (paths);
}

char	*search_command_file(char **paths, char *command)
{
	char	*command_file_path;

	command_file_path = NULL;
	while (*paths)
	{
		command_file_path = ft_strjoin(*paths, command);
		if (access(command_file_path, O_RDONLY) == 0)
		{
			return (command_file_path);
		}
		free (command_file_path);
		paths++;
	}
	return (NULL);
}

char	*find_command_file(char **env, char **cmd)
{
	char	*env_var;
	char	*env_var_value;
	char	**paths;
	char	*command;
	char	*command_file_path;

	env_var = find_env_var("PATH", env);
	env_var_value = get_env_var_value(env_var);
	paths = get_paths(env_var_value);
	command = ft_strjoin("/", cmd[0]);
	command_file_path = search_command_file(paths, command);
	free_double_pointer(paths);
	free(command);
	if (!command_file_path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		return (NULL);
	}
	return (command_file_path);
}
