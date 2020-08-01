/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:47:52 by cyuriko           #+#    #+#             */
/*   Updated: 2019/09/12 17:47:52 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

int				float_len_b(long double flat)
{
	int			len;

	if (signbit(flat))
		flat *= -1;
	len = (flat >= 1.0) ? 0 : 1;
	while (flat >= 1.0)
	{
		flat /= 10;
		len++;
	}
	return (len);
}

void			do_float_part_b(long double flat, char **data,
		t_struct *f, int i)
{
	char		*str;
	int			digit;
	int			len;

	str = *data;
	len = -1;
	while (++len < f->precision)
	{
		flat *= 10.0;
		digit = flat;
		str[i++] = digit + 48;
		flat -= digit;
	}
	str[i] = '\0';
	len = ft_strlen(str);
	(f->width - len > 0 && f->minus == 0) ?
		print_width_before(f->width - len, len, f) : 0;
}

void			do_whole_part_b(long double flat, char **data,
		t_struct *f, int len)
{
	char		*str;
	int			i;
	long double	whole;
	int			digit;
	long double	temp;

	i = 0;
	str = *data;
	whole = flat;
	digit = flat;
	flat -= digit;
	while (len--)
	{
		digit = whole / ft_pow(10, len);
		str[i++] = digit + 48;
		temp = (long double)digit * ft_pow(10, len);
		whole -= temp;
	}
	if (!f->no_presicion)
		str[i++] = '.';
	do_float_part_b(flat, data, f, i);
}

int				space_or_plus_bf(t_struct *f, long double d)
{
	if (f->plus || signbit(d))
	{
		if (signbit(d))
			f->cplus = '-';
		else
			f->cplus = '+';
	}
	if (f->space)
		f->cspase = ' ';
	return (1);
}

void			ft_print_bf(t_struct *f, va_list ap)
{
	long double	flat;
	char		*str;
	int			len;

	flat = va_arg(ap, long double);
	if (!isfinite(flat) && write_denormal_b(flat, f))
		return ;
	if (!f->precision && (f->precision = !f->no_presicion))
		(f->precision = 6);
	if ((f->plus || f->space || signbit(flat)) && space_or_plus_bf(f, flat))
		signbit(flat) ? flat *= -1 : 0;
	if (((int_fast64_t)(flat * ft_pow(10, f->precision + 1)) % 10) >= 5)
		flat += ft_pow(10, -f->precision);
	len = float_len_b(flat);
	if (!(str = malloc(len + f->precision + 2 - f->no_presicion)))
		return ;
	do_whole_part_b(flat, &str, f, len);
	print_space_plus(f);
	f->len += write(f->fd, str, ft_strlen(str));
	if (f->width > 0 && f->minus == 1)
		print_width_after(f->width - ft_strlen(str), ft_strlen(str), f);
	free(str);
	rezeroing(f);
}
