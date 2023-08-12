/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_second_child_process.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 08:43:18 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/11 18:45:09 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_no_file(char **cmd_2, char *cmd2_file_path)
{
	free_if_cmd_fail(cmd_2, cmd2_file_path);
	exit(CMD_FILE_NOT_FOUND);
}

void	handle_no_permission(char **argv, char **cmd_2, char *cmd2_file_path)
{
	print_error_no_permission(argv[3]);
	free_if_cmd_fail(cmd_2, cmd2_file_path);
	exit(PERMISSION_DENIED);
}

void	handle_general_errors(char **cmd_2, char *cmd2_file_path)
{
	free_if_cmd_fail(cmd_2, cmd2_file_path);
	exit(GENERAL_ERROR);
}

void	handle_second_child_process(char **argv, char **env, int *fd)
{
	char	*cmd2_file_path;
	char	**cmd_2;
	int		open_result;
	int		exec_result;

	cmd_2 = NULL;
	cmd2_file_path = NULL;
	if (!open_file(argv[4], &open_result, O_RDWR | O_CREAT | O_TRUNC, 0666))
		exit(FILE_NOT_FOUND);
	handle_fd(fd[1], open_result, fd[0]);
	cmd_2 = ft_split(argv[3], ' ');
	if (access(cmd_2[0], F_OK) == -1)
		cmd2_file_path = find_command_file(env, cmd_2);
	exec_result = run_command(env, cmd_2, cmd2_file_path);
	if (exec_result == -1 && errno == ENOENT)
		handle_no_file(cmd_2, cmd2_file_path);
	else if (exec_result == -1 && errno == 13)
		handle_no_permission(argv, cmd_2, cmd2_file_path);
	else
		handle_general_errors(cmd_2, cmd2_file_path);
}
