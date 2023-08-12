/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:24:13 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/11 20:33:44 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "typedef.h"

int		handle_first_child_process(char **argv, char **env, int *fd);
char	*find_command_file(char **env, char **cmd);
void	free_double_pointer(char **ptr);
void	handle_second_child_process(char **argv, char **env, int *fd);
void	print_error_no_file(char *argv);
int		run_command(char **env, char **cmd, char *cmd_file_path);
void	handle_fd(int fd_close, int fd_dup_out, int fd_dup_in);
void	free_if_cmd_fail(char **cmd, char *cmd_file_path);
int		open_file(char *argv, int *open_result, int flag, int permission);
int		wait_for_pids(int *fd, int id_1, int id_2);
void	print_error_no_permission(char *argv);

#endif
