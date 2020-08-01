/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nondecimal_width.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:46:42 by samymone          #+#    #+#             */
/*   Updated: 2019/08/12 15:46:44 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nondec_width_before(int avail_wid, int len_p, t_struct *f, char c)
{
	int	g;

	g = f->precision - len_p;
	(f->precision > 0 && g > 0) ? avail_wid -= g : 1;
	if (avail_wid >= 1 && f->hash)
		(c == 'o') ? (g -= 1) : g;
	f->width < len_p ? (avail_wid = g) : (avail_wid -= f->hash);
	((c == 'x' || c == 'X') && f->hash) ? avail_wid-- : 1;
	if (f->precision > f->width && f->precision > len_p)
	{
		avail_wid = f->precision - len_p;
		if (f->hash)
			c == 'o' ? (avail_wid -= 1) : (avail_wid);
		g = avail_wid;
	}
	if (f->zero == 1 && f->precision == 0)
	{
		alternative_output(f, c);
		while (avail_wid-- > 0)
			f->len += write(f->fd, "0", 1);
	}
	if (!(f->precision > f->width && f->precision > len_p))
		while (avail_wid-- > 0)
			f->len += write(f->fd, " ", 1);
	extra_nondec_before(avail_wid, g, f, c);
}

void	extra_nondec_before(int av_wid, int g, t_struct *f, char c)
{
	if (f->zero == 0 || (f->zero == 1 && f->precision))
		alternative_output(f, c);
	while (g-- > 0)
		f->len += write(f->fd, "0", 1);
	if (f->zero == 1 && f->precision == 0)
		while (av_wid-- > 0)
			f->len += write(f->fd, "0", 1);
}

void	print_nondec_width_after(int avail_wid, int len_p, t_struct *f, char c)
{
	int	g;

	g = f->precision - len_p - f->hash;
	if (f->precision > 0 && g > 0)
		avail_wid -= g;
	if (avail_wid >= 1 && f->hash && f->precision < f->width)
		avail_wid--;
	((c == 'x' || c == 'X') && f->hash) ? avail_wid-- : 1;
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
