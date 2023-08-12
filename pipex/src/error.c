/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:44:35 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/10 17:57:37 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error_no_file(char *argv)
{
	ft_putstr_fd("no such file or directory: ", 2);
	ft_putendl_fd(argv, 2);
}

void	print_error_no_permission(char *argv)
{
	ft_putstr_fd("permission denied: ", 2);
	ft_putendl_fd(argv, 2);
}
