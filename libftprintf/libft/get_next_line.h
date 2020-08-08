/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:23:55 by cyuriko           #+#    #+#             */
/*   Updated: 2020/08/08 14:26:14 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 8000

int				get_next_line(const int fd, char **line);

typedef struct	s_fd_list_struct
{
	char					*str;
	int						fd;
	struct s_fd_list_struct	*next;
	struct s_fd_list_struct	*prev;
}				t_fd_list;

#endif
