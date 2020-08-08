/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_else_details.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:49:14 by samymone          #+#    #+#             */
/*   Updated: 2020/08/08 14:26:59 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			specifier2(char c, t_struct *f, va_list ap)
{
	if (c == 'f')
		ft_print_f(f, ap);
	else if ((c == 'd' || c == 'i') && f->init_l == 0 && f->init_h == 0)
		ft_print_d(f, ap);
	else if (c == 'u' && f->init_l == 0 && f->init_h == 0)
		ft_print_u(f, ap);
	else if (c == 'p')
		ft_print_p(f, ap);
	else if ((c == 'o' && f->init_l == 0 && f->init_h == 0))
		ft_print_o(f, ap);
	else if ((c == 'x' || c == 'X') && f->init_l == 0 && f->init_h == 0)
		ft_print_x(f, ap, c);
	else if (c == 'C' || c == 'b' || c == 'r')
		bonus_specifier(c, f, ap);
}

void			expanded_specifier(char c, t_struct *f)
{
	if (c == 'l' || c == 'j' || c == 'z')
	{
		if (!(f->init_l))
			f->init_l = 1;
		else
			f->init_l = 2;
	}
	else if (c == 'h')
	{
		if (!(f->init_h))
			f->init_h = 1;
		else
			f->init_h = 2;
	}
	else
		f->int_bl = 1;
}

void			search_else_details(const char *s, t_struct *f, va_list ap)
{
	if (f->start && ft_strchr(s, '*') && !f->width)
		f->width = va_arg(ap, int);
	if (f->start && ft_strchr("+- 0#", s[f->i]))
		flags(f, s[f->i]);
	else if (f->start && ft_strchr("123456789", s[f->i]))
		determine_width(s + f->i, f);
	else if (f->start && s[f->i] == '.')
		determine_presicion(s + f->i + 1, f);
	else if (f->start && ft_strchr("jzlhL", s[f->i]))
		expanded_specifier(s[f->i], f);
	else if (f->start && ft_strchr("cspfdiouxXCbrfDOU", s[f->i]))
		specifier(s[f->i], f, ap);
	else if (s[f->i] != '%' && s[f->i] != '*')
		f->len += write(f->fd, &(s[f->i]), 1);
}
