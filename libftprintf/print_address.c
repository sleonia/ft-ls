/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:14:43 by samymone          #+#    #+#             */
/*   Updated: 2019/07/22 18:14:44 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_p(t_struct *f, va_list ap)
{
	u_int64_t	p;
	char		*inter;
	size_t		len;
	size_t		i;

	p = va_arg(ap, u_int64_t);
	inter = ft_itoa_base(p, 16, 'x');
	len = ((f->precision > (int)ft_strlen(inter)) ? f->precision
			: ft_strlen(inter));
	(!p && f->was_presicion && !f->precision) ? (len = 2) : (len += 2);
	(f->width - len > 0 && f->minus == 0) ?
		print_width_before(f->width - len, len, f) : print_space_plus(f);
	i = 1;
	f->len += write(1, "0x", 2);
	while (++i < len)
	{
		if (i >= len - ft_strlen(inter))
			f->len += write(1, inter + ft_strlen(inter) - len + i, 1);
		else
			f->len += write(1, "0", 1);
	}
	if (f->width > 0 && f->minus == 1)
		print_width_after(f->width - len, len, f);
	free((void*)inter);
}
