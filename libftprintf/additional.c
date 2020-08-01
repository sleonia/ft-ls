/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:54:19 by samymone          #+#    #+#             */
/*   Updated: 2019/09/12 17:36:21 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

int			check_nums(t_struct *f, int nb)
{
	if (!nb)
	{
		if ((f->width && f->no_presicion == 1) || (f->width && !f->precision &&
			f->was_presicion))
		{
			f->width += 1;
			print_width(f);
			rezeroing(f);
			return (1);
		}
		if (f->no_presicion == 1 && nb == 0)
		{
			rezeroing(f);
			return (1);
		}
	}
	return (0);
}

int			chek_oct_hex(t_struct *f, unsigned int nb, int flag)
{
	if (flag && f->hash && f->no_presicion && nb == 0)
	{
		f->len += write(f->fd, ft_itoa(0), 1);
		return (1);
	}
	if (f->width && f->no_presicion == 1)
	{
		f->width += 1;
		print_width(f);
		return (1);
	}
	return (0);
}

int			write_denormal(double flat, t_struct *f)
{
	if (isinf(flat))
	{
		if (flat >= 0.0)
			f->len += write(f->fd, "inf", 3);
		else
			f->len += write(f->fd, "-inf", 4);
	}
	else
		f->len += write(f->fd, "nan", 3);
	return (1);
}

int			write_denormal_b(long double flat, t_struct *f)
{
	if (isinf(flat))
	{
		if (flat >= 0.0)
			f->len += write(f->fd, "inf", 3);
		else
			f->len += write(f->fd, "-inf", 4);
	}
	else
		f->len += write(f->fd, "nan", 3);
	return (1);
}
