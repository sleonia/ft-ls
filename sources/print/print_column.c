/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:39:16 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/09 18:01:06 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print/print.h"
#include "utils/utils.h"
#include "types.h"

static t_matrix	**make_matrix(int files_count, t_file *files,
							const t_flags *flags)
{
	t_matrix	**matrix;
	int			i;
	t_file		*tmp;

	matrix = (t_matrix**)ft_memalloc(sizeof(t_matrix*) * (files_count + 1));
	i = 0;
	tmp = files->files_inside;
	while (i < files_count && tmp)
	{
		if (flags->a || (!flags->a && tmp->name[0] != '.'))
		{
			matrix[i] = (t_matrix*)ft_memalloc(sizeof(t_matrix));
			matrix[i]->name = ft_strdup(tmp->name);
			matrix[i]->st_mode = tmp->stat.st_mode;
			i++;
		}
		tmp = tmp->next;
	}
	return (matrix);
}

static t_cols	*init_cols_info(t_file *file)
{
	t_cols	*cols_info;
	t_conf	*conf;

	conf = file->conf ? file->conf : file->origin->conf;
	cols_info = (t_cols*)ft_memalloc(sizeof(t_cols));
	cols_info->max_file_len = conf->name_len;
	cols_info->files_actual = conf->count_actual;
	cols_info->files_count_total = conf->count_total;
	ioctl(STDIN_FILENO, TIOCGSIZE, &cols_info->ts);
	cols_info->term_width = cols_info->ts.ts_cols;
	if (!cols_info->term_width)
		cols_info->term_width = 80;
	cols_info->cols = cols_info->term_width
			/ (cols_info->max_file_len + 8);
	if (!cols_info->cols)
		cols_info->cols = 1;
	cols_info->files_per_col = cols_info->files_actual / cols_info->cols;
	if (cols_info->files_per_col * cols_info->cols < cols_info->files_actual)
		cols_info->files_per_col++;
	return (cols_info);
}

static void		print_row(t_cols *cols, t_matrix **matrix)
{
	int col;
	int file_in_row_counter;
	int i;

	col = 1;
	file_in_row_counter = 0;
	while (file_in_row_counter < cols->cols)
	{
		i = cols->row + (col - 1) * (cols->files_per_col);
		if (i >= cols->files_actual)
		{
			col = 1;
			cols->row++;
			file_in_row_counter = 0;
			ft_printf("\n");
			continue;
		}
		print_with_color(matrix[i]->st_mode, matrix[i]->name,
				cols->max_file_len + 7);
		file_in_row_counter++;
		cols->files_done++;
		col++;
		if (cols->files_done == cols->files_actual)
			break ;
	}
}

static void		print_block(t_cols *cols_info, t_matrix **matrix)
{
	while (cols_info->files_done < cols_info->files_actual)
	{
		print_row(cols_info, matrix);
		cols_info->row++;
		ft_printf("\n");
	}
}

void			print_column(t_file *files, const t_flags *flags)
{
	t_cols			*cols_info;
	t_matrix		**matrix;

	if (!files)
		return ;
	cols_info = init_cols_info(files);
	matrix = make_matrix(cols_info->files_actual, files, flags);
	print_block(cols_info, matrix);
	free_matrix(cols_info, matrix);
}
