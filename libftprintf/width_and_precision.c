/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:54:37 by samymone          #+#    #+#             */
/*   Updated: 2019/08/03 15:54:39 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		determine_width(const char *str, t_struct *f)
{
	int i;

	i = 0;

	while (*str >= '0' && *str <= '9')
	{
		i++;
		str++;
	}
	f->width = ft_atoi(str - i);
	f->i = f->i + i - 1;
}

void		determine_presicion(const char *str, t_struct *f)
{
	int	i;
	int	p;

	i = 0;
	f->was_presicion = 1;
	while (*str >= '0' && *str <= '9')
	{
		i++;
		str++;
	}
	p = ft_atoi(str - i);
	if (i > 0 && (p != 0 || (*(str - i) == '0')))
	{
		f->precision = p;
		f->i = f->i + i;
	}
	else if ((i == 0 || p == 0) && !(f->hash))
		f->no_presicion = 1;
	else if (p == 0 && f->hash)
		f->no_presicion = 1;
}

void		print_width(t_struct *f)
{
	int i;

	i = f->width - 1;
	if (f->zero)
		while (i-- > 0)
			f->len += write(f->fd, "0", 1);
	else
		while (i-- > 0)
			f->len += write(f->fd, " ", 1);
}

void		rezeroing(t_struct *f)
{
	f->plus = 0;
	f->space = 0;
	f->zero = 0;
	f->width = 0;
	f->precision = 0;
	f->minus = 0;
	f->hash = 0;
	f->chash = NULL;
	f->int_bl = 0;
	f->was_presicion = 0;
	f->cplus = (char)NULL;
}
