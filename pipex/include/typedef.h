/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:42:32 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/10 18:01:19 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef enum s_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef enum s_return
{
	SUCCESS = 0,
	GENERAL_ERROR,
	INVALID_INPUT,
	FILE_NOT_FOUND,
	PIPE_NOT_CREATED,
	FORK_NOT_CREATED,
	COULD_NOT_WRITE,
	PERMISSION_DENIED = 126,
	CMD_FILE_NOT_FOUND = 127
}	t_return;

extern char	**environ;

#endif
