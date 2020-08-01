/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:11:33 by samymone          #+#    #+#             */
/*   Updated: 2019/07/21 15:11:36 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				alternative_output(t_struct *f, char c)
{
	if (f->hash && c == 'o')
	{
		if (!(f->chash = malloc(sizeof(char))))
			;
		f->chash = "0";
		f->len += write(f->fd, f->chash, 1);
	}
	else if (f->hash && (c == 'x' || c == 'X'))
	{
		if ((f->chash = malloc(sizeof(char) * 2)))
		{
			if (c == 'x')
				f->chash = "0x";
			else if (c == 'X')
				f->chash = "0X";
			f->len += write(f->fd, (*f).chash, 2);
		}
	}
}

void				ft_print_o(t_struct *f, va_list ap)
{
	unsigned int	o;
	char			*extra_o;

	o = va_arg(ap, unsigned int);
	if (chek_oct_hex(f, o, 1))
		return ;
	(o == 0) ? rezeroing(f) : 0;
	if (f->no_presicion == 1 && !(f->hash))
		return ;
	extra_o = ft_itoa_base(o, 8, o);
	o = ft_strlen((extra_o));
	if (f->width - o > 0 && f->minus == 0)
	{
		print_nondec_width_before(f->width - o, o, f, 'o');
		rezeroing(f);
	}
	(f->hash) ? alternative_output(f, 'o') : 0;
	if (f->width < f->precision || f->minus)
		extra_case(f, o, 'o');
	f->len += write(f->fd, extra_o, o);
	if (f->width > 0 && f->minus == 1)
		print_nondec_width_after(f->width - o, o, f, 'o');
	else if (f->width - f->precision - f->hash && f->minus > 0)
		extra_case_2(f, o);
	rezeroing(f);
}

void				ft_print_x(t_struct *f, va_list ap, char c)
{
	unsigned int	x;
	char			*extra_x;

	x = va_arg(ap, unsigned int);
	if (chek_oct_hex(f, x, 0))
		return ;
	(x == 0) ? rezeroing(f) : 0;
	if (f->no_presicion == 1)
		return ;
	extra_x = (c == 'x' ? ft_itoa_base(x, 16, 'x') : ft_itoa_base(x, 16, 'X'));
	x = ft_strlen(extra_x);
	if (f->width - x > 0 && f->minus == 0)
	{
		print_nondec_width_before(f->width - x, x, f, c);
		rezeroing(f);
	}
	(f->hash) ? alternative_output(f, c) : 0;
	(f->width < f->precision || f->minus) ? extra_case(f, x, c) : 0;
	f->len += write(f->fd, extra_x, x);
	if (f->width > 0 && f->minus == 1)
		print_nondec_width_after(f->width - x, x, f, c);
	else if (f->width - f->precision - f->hash && f->minus > 0)
		extra_case_2(f, x);
	rezeroing(f);
}
