/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:45:07 by samymone          #+#    #+#             */
/*   Updated: 2019/07/24 15:45:09 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						check_num(signed long int d, t_struct *f)
{
	char				*extra_d;

	if (d < -9223372036854775807)
	{
		if ((extra_d = ft_itoa(d)))
		{
			if (d < 0)
				f->len += write(1, "-", 1);
			f->len += write(f->fd, extra_d, ft_strlen(extra_d));
			free(extra_d);
		}
		return (1);
	}
	return (0);
}

void					ft_print_ld(t_struct *f, va_list ap)
{
	signed long int		d;
	char				*extra_d;

	d = va_arg(ap, signed long int);
	if (check_num(d, f))
		return ;
	if (f->plus || f->space || d < 0)
	{
		space_or_plus(f, d);
		d < 0 ? d *= (-1) : d;
	}
	extra_d = ft_itoa(d);
	d = ft_strlen(extra_d);
	(f->width - d > 0 && f->minus == 0) ?
		print_width_before(f->width - d, d, f) : 0;
	(f->plus || f->space || f->cplus == '-') ? print_space_plus(f) : 0;
	(f->width < f->precision || f->minus) ? extra_case(f, d, 'd') : 0;
	f->len += write(f->fd, extra_d, d);
	if (f->width > 0 && f->minus == 1)
		print_width_after(f->width - d, d, f);
	else if (f->width - f->precision - f->plus - f->space > 0 && f->minus == 1)
		extra_case_2(f, d);
	free((void*)extra_d);
	rezeroing(f);
}

void					ft_print_lu(t_struct *f, va_list ap)
{
	unsigned long int	u;
	const char			*extra_u;

	u = va_arg(ap, unsigned long int);
	extra_u = ft_itoa2(u);
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

void					ft_print_lo(t_struct *f, va_list ap)
{
	unsigned long int	o;
	const char			*extra_o;

	o = va_arg(ap, unsigned long int);
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

void					ft_print_lx(t_struct *f, va_list ap, char c)
{
	unsigned long int	x;
	const char			*extra_x;

	x = va_arg(ap, unsigned long int);
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
