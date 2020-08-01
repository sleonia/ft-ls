/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:43:07 by samymone          #+#    #+#             */
/*   Updated: 2019/07/22 18:43:10 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_b(t_struct *f, va_list ap)
{
	unsigned long int	b;
	char				*extra_b;
	int					len;

	b = va_arg(ap, unsigned long int);
	len = len_value(b, 2);
	extra_b = (char*)malloc(sizeof(char) * len);
	extra_b[len--] = '\0';
	while (len > -1)
	{
		extra_b[len--] = b % 2 + '0';
		b /= 2;
	}
	f->len += write(f->fd, extra_b, ft_strlen(extra_b));
	free(extra_b);
}
