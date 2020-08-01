/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded_allocation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 19:19:16 by samymone          #+#    #+#             */
/*   Updated: 2019/08/13 19:19:18 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		long_allocation(t_struct *f, char c, va_list ap)
{
	if (f->init_l == 1)
	{
		if (c == 'd' || c == 'i')
			ft_print_ld(f, ap);
		else if (c == 'o')
			ft_print_lo(f, ap);
		else if (c == 'u')
			ft_print_lu(f, ap);
		else if (c == 'x' || c == 'X')
			ft_print_lx(f, ap, c);
	}
	else if (f->init_l == 2)
	{
		if (c == 'd' || c == 'i')
			ft_print_lld(f, ap);
		else if (c == 'o')
			ft_print_llo(f, ap);
		else if (c == 'u')
			ft_print_llu(f, ap);
		else if (c == 'x' || c == 'X')
			ft_print_llx(f, ap, c);
	}
}

void		short_allocation(t_struct *f, char c, va_list ap)
{
	if (f->init_h == 1)
	{
		if (c == 'd' || c == 'i')
			ft_print_hd(f, ap);
		else if (c == 'o')
			ft_print_ho(f, ap);
		else if (c == 'u')
			ft_print_hu(f, ap);
		else if (c == 'x' || c == 'X')
			ft_print_hx(f, ap, c);
		else if (c == 'U')
			ft_print_lu(f, ap);
	}
	else if (f->init_h == 2)
	{
		if (c == 'd' || c == 'i')
			ft_print_hhd(f, ap);
		else if (c == 'o')
			ft_print_hho(f, ap);
		else if (c == 'u')
			ft_print_hhu(f, ap);
		else if (c == 'x' || c == 'X')
			ft_print_hhx(f, ap, c);
	}
}
