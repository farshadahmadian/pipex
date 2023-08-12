/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_first_child_process.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:54:15 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/11 20:03:17 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_first_child_process(char **argv, char **env, int *fd)
{
	char	*cmd1_file_path;
	char	**cmd_1;
	int		open_result;
	int		exec_result;

	cmd_1 = NULL;
	cmd1_file_path = NULL;
	if (!open_file(argv[1], &open_result, O_RDONLY, 0444))
		return (FILE_NOT_FOUND);
	handle_fd(fd[0], fd[1], open_result);
	cmd_1 = ft_split(argv[2], ' ');
	if (access(cmd_1[0], F_OK) == -1)
		cmd1_file_path = find_command_file(env, cmd_1);
	exec_result = run_command(env, cmd_1, cmd1_file_path);
	if (exec_result == -1 && errno == ENOENT)
		return (free_if_cmd_fail(cmd_1, cmd1_file_path), CMD_FILE_NOT_FOUND);
	else if (exec_result == -1 && errno == 13)
	{
		print_error_no_permission(argv[2]);
		return (free_if_cmd_fail(cmd_1, cmd1_file_path), PERMISSION_DENIED);
	}
	else
		return (free_if_cmd_fail(cmd_1, cmd1_file_path), GENERAL_ERROR);
}
