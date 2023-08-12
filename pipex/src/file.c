/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:03:38 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/09 13:16:57 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_fd(int fd_close, int fd_dup_out, int fd_dup_in)
{
	close(fd_close);
	dup2(fd_dup_out, STDOUT_FILENO);
	close(fd_dup_out);
	dup2(fd_dup_in, STDIN_FILENO);
	close(fd_dup_in);
}

int	open_file(char *argv, int *open_result, int flag, int permission)
{
	*open_result = open(argv, flag, permission);
	if (*open_result == -1)
	{
		print_error_no_file(argv);
		return (FALSE);
	}
	return (TRUE);
}
