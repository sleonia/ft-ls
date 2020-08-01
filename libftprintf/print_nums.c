/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:45:50 by samymone          #+#    #+#             */
/*   Updated: 2019/07/20 19:45:52 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					space_or_plus(t_struct *f, long long int d)
{
	if (f->plus || d < 0)
	{
		if (d >= 0 || (d >= 0 && f->init_l))
			f->cplus = '+';
		else
			f->cplus = '-';
	}
	if (f->space)
		f->cspase = ' ';
	return (1);
}

void				print_space_plus(t_struct *f)
{
	if (f->plus == 1 || f->cplus == '-')
		f->len += write(f->fd, &(f->cplus), 1);
	else if (f->space)
		f->len += write(f->fd, &(f->cspase), 1);
}

void				ft_print_d(t_struct *f, va_list ap)
{
	int				d;
	const char		*extra_d;

	d = va_arg(ap, int);
	if (check_nums(f, d))
		return ;
	if ((f->plus || f->space || d < 0) && space_or_plus(f, d))
		d < 0 ? d *= (-1) : d;
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

void				ft_print_u(t_struct *f, va_list ap)
{
	unsigned int	u;
	const char		*extra_u;

	u = va_arg(ap, unsigned int);
	if (check_nums(f, u))
		return ;
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
	rezeroing(f);
}
