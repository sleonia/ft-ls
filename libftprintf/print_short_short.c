/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_short_short.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 15:24:35 by samymone          #+#    #+#             */
/*   Updated: 2019/08/14 15:24:37 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_print_hhd(t_struct *f, va_list ap)
{
	int				d;
	const char		*extra_d;

	d = (signed char)va_arg(ap, int);
	if (f->plus || f->space || d < 0)
	{
		space_or_plus(f, d);
		d < 0 ? d *= (-1) : d;
	}
	extra_d = ft_itoa(d);
	d = ft_strlen(extra_d);
	if (f->width - d > 0 && f->minus == 0)
		print_width_before(f->width - d, d, f);
	if (f->plus || f->space || f->cplus == '-')
		print_space_plus(f);
	if (f->width < f->precision || f->minus)
		extra_case(f, d, 'd');
	f->len += write(f->fd, extra_d, d);
	if (f->width > 0 && f->minus == 1)
		print_width_after(f->width - d, d, f);
	else if (f->width - f->precision - f->plus - f->space > 0 && f->minus == 1)
		extra_case_2(f, d);
	free((void*)extra_d);
	rezeroing(f);
}

void				ft_print_hhu(t_struct *f, va_list ap)
{
	unsigned char	u;
	const char		*extra_u;

	u = (unsigned char)va_arg(ap, int);
	extra_u = ft_itoa(u);
	u = ft_strlen(extra_u);
	if ((f->width - u > 0 && f->minus == 0) || f->zero == 1)
		print_unsigned_width_before(f->width - u, u, f);
	else if (f->minus == 1 && f->precision && f->width < f->precision)
		extra_case_3(f, u);
	else if (f->minus == 1 && f->width >= f->precision)
		extra_case_4(f, u);
	f->len += write(f->fd, extra_u, u);
	if (f->width - u > 0 && f->minus == 1)
		print_unsigned_width_after(f->width - u, u, f);
	free((void*)extra_u);
	rezeroing(f);
}

void				ft_print_hho(t_struct *f, va_list ap)
{
	unsigned char	o;
	const char		*extra_o;

	o = (signed char)va_arg(ap, int);
	extra_o = ft_itoa_base(o, 8, o);
	o = ft_strlen((extra_o));
	if (f->width - o > 0 && f->minus == 0)
	{
		print_nondec_width_before(f->width - o, o, f, 'o');
		rezeroing(f);
	}
	if (f->hash)
		alternative_output(f, 'o');
	if (f->width < f->precision || f->minus)
		extra_case(f, o, 'o');
	f->len += write(f->fd, extra_o, o);
	if (f->width > 0 && f->minus == 1)
		print_nondec_width_after(f->width - o, o, f, 'o');
	else if (f->width - f->precision - f->hash && f->minus > 0)
		extra_case_2(f, o);
	free((void*)extra_o);
	rezeroing(f);
}

void				ft_print_hhx(t_struct *f, va_list ap, char c)
{
	unsigned char	x;
	const char		*extra_x;

	x = va_arg(ap, int);
	extra_x = (c == 'x' ? ft_itoa_base(x, 16, 'x') : ft_itoa_base(x, 16, 'X'));
	x = ft_strlen(extra_x);
	if (f->width - x > 0 && f->minus == 0)
	{
		print_nondec_width_before(f->width - x, x, f, c);
		rezeroing(f);
	}
	if (f->hash)
		alternative_output(f, c);
	if (f->width < f->precision || f->minus)
		extra_case(f, x, c);
	f->len += write(f->fd, extra_x, x);
	if (f->width > 0 && f->minus == 1)
		print_nondec_width_after(f->width - x, x, f, c);
	else if (f->width - f->precision - f->hash && f->minus > 0)
		extra_case_2(f, x);
	free((void*)extra_x);
	rezeroing(f);
}
