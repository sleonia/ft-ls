/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:57:38 by samymone          #+#    #+#             */
/*   Updated: 2019/08/08 19:57:40 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_width_before(int avail_wid, int len_param, t_struct *f)
{
	int	g;

	g = f->precision - len_param;
	if (f->precision > 0 && g > 0)
		avail_wid -= g;
	if (avail_wid >= 1 && (f->plus || f->space || f->cplus == '-'))
		avail_wid--;
	f->width < len_param ? (avail_wid = g) : avail_wid;
	if (f->zero == 1 && f->precision == 0)
	{
		print_space_plus(f);
		while (avail_wid-- > 0)
			f->len += write(f->fd, "0", 1);
	}
	while (avail_wid-- > 0)
		f->len += write(f->fd, " ", 1);
	if (f->zero == 0 || (f->zero == 1 && f->precision))
		print_space_plus(f);
	while (g-- > 0)
		f->len += write(f->fd, "0", 1);
	if (f->zero == 1 && f->precision == 0)
		while (avail_wid-- > 0)
			f->len += write(f->fd, "0", 1);
	rezeroing(f);
}

void		extra_case(t_struct *f, int len_param, char c)
{
	int g;

	g = f->precision - len_param;
	if (f->hash && (c == 'x' || c == 'X'))
		;
	else if (f->hash)
		g--;
	while (g > 0)
	{
		f->len += write(f->fd, "0", 1);
		g--;
	}
}

void		extra_case_2(t_struct *f, int len_param)
{
	int g;

	g = f->width - f->precision - f->plus - f->space;
	if (f->precision < len_param && f->cplus == '-')
		g--;
	while (g > 0)
	{
		f->len += write(f->fd, " ", 1);
		g--;
	}
}

void		print_width_after(int avail_wid, int len_param, t_struct *f)
{
	int	g;

	g = f->precision - len_param;
	if (f->precision > 0 && g > 0)
		avail_wid -= g;
	if (avail_wid >= 1 && (f->plus || f->space || f->cplus == '-'))
		avail_wid--;
	if (!f->minus)
		while (g > 0)
		{
			f->len += write(f->fd, "0", 1);
			g--;
		}
	while (avail_wid > 0)
	{
		f->len += write(f->fd, " ", 1);
		avail_wid--;
	}
}
