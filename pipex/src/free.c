/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:45:29 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/10 18:00:44 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_double_pointer(char **ptr)
{
	char	*temp;
	char	**temp2;

	if (!ptr)
		return ;
	temp2 = ptr;
	while (*ptr)
	{
		temp = *ptr;
		free(temp);
		temp = NULL;
		ptr++;
	}
	free(temp2);
	ptr = NULL;
}

void	free_if_cmd_fail(char **cmd, char *cmd_file_path)
{
	free_double_pointer(cmd);
	free(cmd_file_path);
}
