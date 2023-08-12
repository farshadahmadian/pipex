/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:23:13 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/12 09:12:00 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		fd[2];
	int		id_1;
	int		id_2;
	int		exit_status;

	exit_status = 0;
	if (argc != 5)
		return (INVALID_INPUT);
	if (pipe(fd) == -1)
		return (PIPE_NOT_CREATED);
	id_1 = fork();
	if (id_1 == -1)
		return (FORK_NOT_CREATED);
	if (id_1 == 0)
		return (handle_first_child_process(argv, environ, fd));
	id_2 = fork();
	if (id_2 == -1)
	{
		waitpid(id_1, NULL, 0);
		return (FORK_NOT_CREATED);
	}
	if (id_2 == 0)
		handle_second_child_process(argv, environ, fd);
	exit_status = wait_for_pids(fd, id_1, id_2);
	return (exit_status);
}
