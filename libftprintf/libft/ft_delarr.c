/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 13:26:21 by cyuriko           #+#    #+#             */
/*   Updated: 2019/08/21 13:57:34 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delarr(void **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	ft_memdel(arr);
}
