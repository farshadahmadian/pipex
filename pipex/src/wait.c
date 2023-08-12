/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:39:22 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/10 10:11:52 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_for_pids(int *fd, int id_1, int id_2)
{
	int	wait_first_status;
	int	wait_second_status;
	int	is_first_exited;
	int	is_second_exited;
	int	exit_status;

	exit_status = 0;
	close(fd[0]);
	close(fd[1]);
	waitpid(id_1, &wait_first_status, 0);
	is_first_exited = WIFEXITED(wait_first_status);
	if (is_first_exited)
	{
		exit_status = WEXITSTATUS(wait_first_status);
	}
	waitpid(id_2, &wait_second_status, 0);
	is_second_exited = WIFEXITED(wait_second_status);
	if (is_second_exited)
	{
		exit_status = WEXITSTATUS(wait_second_status);
	}
	return (exit_status);
}
