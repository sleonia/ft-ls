/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_illegal_opt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:42:49 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 14:43:11 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print/print.h"

/*
** \file
** \brief
*/

void		print_illegal_opt(const char symb)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(symb);
	ft_putstr("\n\
usage: ls [-@ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1%] [file ...]\n");
}
