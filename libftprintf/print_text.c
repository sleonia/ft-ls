/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:45:21 by samymone          #+#    #+#             */
/*   Updated: 2020/08/08 14:27:15 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(t_struct *f, va_list ap)
{
	char	*s;
	int		len_s;

	s = va_arg(ap, char*);
	if (f->width && f->no_presicion == 1)
	{
		f->width += 1;
		print_width(f);
		return ;
	}
	if (s == NULL)
		f->len += write(f->fd, "(null)", 6);
	(s != NULL) ? len_s = ft_strlen(s) : 0;
	if (f->width && f->minus == 0)
		print_text_width_before(f->width - len_s, len_s, f);
	if (f->precision && f->precision < len_s)
		len_s = f->precision;
	if (s != NULL)
		f->len += write(f->fd, s, len_s);
	if (f->width && f->minus == 1)
		print_text_width_after(f->width - len_s, f);
	rezeroing(f);
}

void	ft_print_c(t_struct *f, va_list ap)
{
	int t;

	t = va_arg(ap, int);
	if (f->width && f->minus == 0)
		print_text_width_before(f->width - 1, 1, f);
	f->len += write(f->fd, &t, 1);
	if (f->width && f->minus == 1)
		print_text_width_after(f->width - 1, f);
	rezeroing(f);
}

void	print_text_width_before(int avail_wid, int len_param, t_struct *f)
{
	if (f->precision)
		if (f->precision < len_param)
			avail_wid += (len_param - f->precision);
	if (f->zero && !(f->precision))
		while (avail_wid-- > 0)
			f->len += write(f->fd, "0", 1);
	while (avail_wid-- > 0)
		f->len += write(f->fd, " ", 1);
}

void	print_text_width_after(int avail_wid, t_struct *f)
{
	while (avail_wid-- > 0)
		f->len += write(f->fd, " ", 1);
}
