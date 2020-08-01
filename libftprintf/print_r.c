/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:46:54 by samymone          #+#    #+#             */
/*   Updated: 2019/08/01 15:46:58 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nonprintable(int c, t_struct *f)
{
	if (c == 0)
		f->len += write(f->fd, "@", 1);
	else if (c == 1)
		f->len += write(f->fd, "A", 1);
	else if (c == 2)
		f->len += write(f->fd, "B", 1);
	else if (c == 3)
		f->len += write(f->fd, "C", 1);
	else if (c == 4)
		f->len += write(f->fd, "D", 1);
	else if (c == 5)
		f->len += write(f->fd, "E", 1);
	else if (c == 6)
		f->len += write(f->fd, "F", 1);
	else if (c == 7)
		f->len += write(f->fd, "G", 1);
	else if (c == 8)
		f->len += write(f->fd, "H", 1);
	else if (c == 9)
		f->len += write(f->fd, "I", 1);
	else if (c == 10)
		f->len += write(f->fd, "J", 1);
	else
		print_nonprintable2(c, f);
}

void	print_nonprintable2(int c, t_struct *f)
{
	if (c == 11)
		f->len += write(f->fd, "K", 1);
	else if (c == 12)
		f->len += write(f->fd, "L", 1);
	else if (c == 13)
		f->len += write(f->fd, "M", 1);
	else if (c == 14)
		f->len += write(f->fd, "N", 1);
	else if (c == 15)
		f->len += write(f->fd, "O", 1);
	else if (c == 16)
		f->len += write(f->fd, "P", 1);
	else if (c == 17)
		f->len += write(f->fd, "Q", 1);
	else if (c == 18)
		f->len += write(f->fd, "R", 1);
	else if (c == 19)
		f->len += write(f->fd, "S", 1);
	else if (c == 20)
		f->len += write(f->fd, "T", 1);
	else if (c == 22)
		f->len += write(f->fd, "U", 1);
	else
		print_nonprintable3(c, f);
}

void	print_nonprintable3(int c, t_struct *f)
{
	if (c == 22)
		f->len += write(f->fd, "V", 1);
	else if (c == 23)
		f->len += write(f->fd, "W", 1);
	else if (c == 24)
		f->len += write(f->fd, "X", 1);
	else if (c == 25)
		f->len += write(f->fd, "Y", 1);
	else if (c == 26)
		f->len += write(f->fd, "Z", 1);
	else if (c == 27)
		f->len += write(f->fd, "[", 1);
	else if (c == 28)
		f->len += write(f->fd, "\\", 1);
	else if (c == 29)
		f->len += write(f->fd, "]", 1);
	else if (c == 30)
		f->len += write(f->fd, "^", 1);
	else if (c == 31)
		f->len += write(f->fd, "_", 1);
	else if (c == 127)
		f->len += write(f->fd, "?", 1);
}

void	ft_print_r(t_struct *f, va_list ap)
{
	int		r;
	char	*extra_r;

	r = va_arg(ap, int);
	if ((r >= 0 && r < 32) || r == 127)
	{
		f->len += write(f->fd, "^", 1);
		print_nonprintable(r, f);
	}
	else if (r >= 32 && r < 127)
	{
		extra_r = ft_itoa(r);
		f->len += write(f->fd, extra_r, ft_strlen(extra_r));
	}
	else
		f->len = 0;
}
