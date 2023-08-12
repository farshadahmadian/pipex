/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:50:41 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/09 12:53:58 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	run_command(char **env, char **cmd, char *cmd_file_path)
{
	int	exec_result;

	if (cmd_file_path)
		exec_result = execve(cmd_file_path, cmd, env);
	else
		exec_result = execve(cmd[0], cmd, env);
	return (exec_result);
}
