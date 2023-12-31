/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:00:55 by fahmadia          #+#    #+#             */
/*   Updated: 2023/08/12 09:09:09 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int *i, va_list args)
{
	int	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	*i += 2;
	return (1);
}
