/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:59:00 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/09 17:59:38 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print/print.h"
#include "utils/utils.h"
#include "libft/libft.h"

void		free_matrix(t_cols *cols, t_matrix **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		ft_strdel(&matrix[i]->name);
		free(matrix[i]);
		i++;
	}
	free(matrix);
	ft_memdel((void**)&cols);
}
