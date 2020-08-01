/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:27:11 by cyuriko           #+#    #+#             */
/*   Updated: 2019/09/11 14:29:33 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_bc(va_list ap)
{
	const char	*s;

	s = va_arg(ap, char*);
	if (!ft_strcmp(s, "RED"))
		write(1, "\x1b[31m", 5);
	if (!ft_strcmp(s, "GREEN"))
		write(1, "\x1b[32m", 5);
	if (!ft_strcmp(s, "YELLOW"))
		write(1, "\x1b[33m", 5);
	if (!ft_strcmp(s, "BLUE"))
		write(1, "\x1b[34m", 5);
	if (!ft_strcmp(s, "CYAN"))
		write(1, "\x1b[35m", 5);
	if (!ft_strcmp(s, "MAGENTA"))
		write(1, "\x1b[36m", 5);
	if (!ft_strcmp(s, "RESET"))
		write(1, "\x1b[0m", 4);
	if (!ft_strcmp(s, "BLINK"))
		write(1, "\x1b[5m", 4);
	if (!ft_strcmp(s, "UNDERLINE"))
		write(1, "\x1b[4m", 4);
}
