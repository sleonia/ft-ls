/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:10:04 by samymone          #+#    #+#             */
/*   Updated: 2019/08/11 18:10:06 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned_width_before(int avail_wid, int len_param, t_struct *f)
{
	int	g;

	g = f->precision - len_param;
	if (f->zero == 0 || (f->zero == 1 && f->precision))
	{
		if (f->precision > 0 && g > 0)
			avail_wid -= g;
		f->width < len_param ? (avail_wid = g) : avail_wid;
		if (f->width > f->precision)
			while (avail_wid-- > 0)
				f->len += write(f->fd, " ", 1);
		while (g-- > 0)
			f->len += write(f->fd, "0", 1);
	}
	else if (f->zero == 1 && f->precision == 0)
		while (avail_wid-- > 0)
			f->len += write(f->fd, "0", 1);
}

void	print_unsigned_width_after(int avail_wid, int len_param, t_struct *f)
{
	int	g;

	g = f->precision - len_param;
	if (f->precision > 0 && g > 0)
		avail_wid -= g;
	while (avail_wid > 0)
	{
		f->len += write(f->fd, " ", 1);
		avail_wid--;
	}
}

void	extra_case_3(t_struct *f, int len_param)
{
	int g;

	g = f->width - f->precision - len_param;
	while (g-- > 0)
		f->len += write(f->fd, "0", 1);
	if (f->width < f->precision)
	{
		g = f->precision - len_param;
		while (g-- > 0)
			f->len += write(f->fd, "0", 1);
	}
}

void	extra_case_4(t_struct *f, int len_param)
{
	int g;

	g = f->precision - len_param;
	while (g-- > 0)
		f->len += write(f->fd, "0", 1);
}
