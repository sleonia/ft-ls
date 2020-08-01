/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:41:30 by samymone          #+#    #+#             */
/*   Updated: 2019/09/11 21:52:59 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "math.h"

t_struct		*zeroing(t_struct *f)
{
	f->i = 0;
	f->len = 0;
	f->hash = 0;
	f->minus = 0;
	f->plus = 0;
	f->precision = 0;
	f->space = 0;
	f->width = 0;
	f->zero = 0;
	f->init_l = 0;
	f->init_h = 0;
	f->int_bl = 0;
	f->no_presicion = 0;
	return (f);
}

t_struct		*create_struct(t_struct *f)
{
	if (!(f = (t_struct*)malloc(sizeof(t_struct))))
		return (NULL);
	f->len = 0;
	f->fd = 1;
	f->start = 0;
	zeroing(f);
	return (f);
}

int				ft_printf(const char *str, ...)
{
	size_t		len;
	va_list		ap;
	t_struct	*f;

	f = NULL;
	len = 0;
	va_start(ap, str);
	if (str[0] == '%' && str[1] == '\0')
		;
	else if (!(ft_strchr(str, '%')))
		len += write(1, str, ft_strlen(str));
	else
	{
		if (!*str || !(f = (create_struct(f))))
			return (-1);
		search_details(str, f, ap);
		len = f->len;
		free(f);
	}
	va_end(ap);
	return (len);
}
