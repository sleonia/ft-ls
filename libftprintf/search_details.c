/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_details.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 17:17:14 by samymone          #+#    #+#             */
/*   Updated: 2019/07/20 19:46:10 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct		flags(t_struct *f, char c)
{
	if (c == '+')
		f->plus = 1;
	else if (c == '-')
		f->minus = 1;
	else if (c == '0')
		f->zero = 1;
	else if (c == '#')
		f->hash = 1;
	else if (c == ' ')
		f->space = 1;
	return (*f);
}

void			specifier(char c, t_struct *f, va_list ap)
{
	f->start = 0;
	if (f->init_l)
		long_allocation(f, c, ap);
	else if (f->init_h)
		short_allocation(f, c, ap);
	else if (f->int_bl)
		ft_print_bf(f, ap);
	else if (c == 'D' || c == 'O' || c == 'U')
		alternative_long(c, f, ap);
	else if (c == 's')
		ft_print_s(f, ap);
	else if (c == 'c')
		ft_print_c(f, ap);
	else
		specifier2(c, f, ap);
	f->init_l = 0;
	f->init_h = 0;
}

void			alternative_long(char c, t_struct *f, va_list ap)
{
	if (c == 'D')
		ft_print_ld(f, ap);
	else if (c == 'O')
		ft_print_lo(f, ap);
	else if (c == 'U')
		ft_print_lu(f, ap);
}

void			bonus_specifier(char c, t_struct *f, va_list ap)
{
	if (c == 'C')
		ft_print_bc(ap);
	else if (c == 'b')
		ft_print_b(f, ap);
	else if (c == 'r')
		ft_print_r(f, ap);
}

void			search_details(const char *s, t_struct *f, va_list ap)
{
	while (s[f->i])
	{
		if (f->start == 0 && s[f->i] == '%')
			f->start = 1;
		else if (s[f->i] == '%' && f->i > 0 && f->start == 1)
		{
			if (f->width && !(f->minus))
				print_width(f);
			f->len += write(f->fd, &(s[f->i]), 1);
			if (f->minus)
				print_width(f);
			f->start = 0;
		}
		else
			search_else_details(s, f, ap);
		f->i++;
	}
}
