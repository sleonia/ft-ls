/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:26:56 by samymone          #+#    #+#             */
/*   Updated: 2019/08/16 16:28:11 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		ft_pow(double x, int y)
{
	long double	temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if ((y % 2) == 0)
		return (temp * temp);
	else
	{
		if (y > 0)
			return (x * temp * temp);
		else
			return (temp * temp / x);
	}
}

int				find_len(unsigned long long int n)
{
	int			len;

	len = (n > 0) ? (0) : (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa2(unsigned long long int n)
{
	char		*str;
	int			len;

	len = find_len(n);
	if (!(str = malloc(sizeof(unsigned long long int) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
