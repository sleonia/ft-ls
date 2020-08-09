#include "print/print.h"
#include "types.h"

typedef  struct s_matrix
{
	char 		*name;
	struct stat *stat_;
}				t_matrix;

static char **make_matrix(int files_count, t_file *files, t_flags *flags)
{
	t_matrix 	**matrix;
	int 		i;
	t_file 		*tmp;

	matrix = (t_matrix**)ft_memalloc(sizeof(t_matrix*) * (files_count + 1));
	i = 0;
	tmp = files->files_inside;
	while (i < files_count && tmp)
	{
		if (flags->a || (!flags->a && tmp->name[0] != '.'))
		{
			matrix[i] = (t_matrix*)ft_memalloc(sizeof(t_matrix));
			matrix[i]->name = ft_strdup(tmp->name);
			matrix[i]->stat_ = &tmp->stat;
			i++;
		}
		tmp = tmp->next;
	}
	return (matrix);
}

static t_cols  *init_cols_info(t_file *file)
{
	t_cols *cols_info;
	cols_info = (t_cols*)ft_memalloc(sizeof(t_cols));
	cols_info->max_file_len = file->conf ? file->conf->name_len : file->origin->conf->name_len;
	cols_info->files_count_actual = file->conf ? file->conf->count_actual : file->origin->conf->count_actual;
	cols_info->files_count_total = file->conf ? file->conf->count_total : file->origin->conf->count_total;
	ioctl(STDIN_FILENO, TIOCGSIZE, &cols_info->ts);
	cols_info->term_width = cols_info->ts.ts_cols;
	if (!cols_info->term_width)
		cols_info->term_width = 80;
//	cols_info->term_width = 104;//del_me;
	cols_info->cols = cols_info->term_width / (cols_info->max_file_len + 4);//do smth
	if (!cols_info->cols)
		cols_info->cols = 1;
	cols_info->normal_files_per_col = cols_info->files_count_actual / cols_info->cols;
	if (cols_info->normal_files_per_col * cols_info->cols < cols_info->files_count_actual)
		cols_info->normal_files_per_col++;

	return (cols_info);
}

static void print_block(t_cols *cols_info, t_matrix **matrix, int rows)
{
	int col;
	int file_in_row_counter;
	int index;
	int row;
	int refuse;

	row = 0;
	while (cols_info->files_done < cols_info->files_count_actual)
	{
		col = 1;
		file_in_row_counter = 0;
		while (file_in_row_counter < cols_info->cols)
		{
			refuse = (cols_info->files_count_actual - cols_info->files_done) < cols_info->cols ? 1 : 0;
			index = row + (col - 1)  * (cols_info->normal_files_per_col);
			if (index >= cols_info->files_count_actual)
			{
				col = 1;
				row++;
				file_in_row_counter = 0;
				ft_printf("\n");
				continue;
			}
	//		ft_printf("%-*s ", cols_info->max_file_len + 1, matrix[index]);
			print_with_color(matrix[index]->stat_, matrix[index]->name, cols_info->max_file_len + 1);
//			ft_printf("%s", ANSI_COLOR_BOLD_CYAN);
//			ft_printf("%-*s", cols_info->max_file_len + 1, matrix[index]);
//			ft_printf("%s", ANSI_COLOR_RESET);
			file_in_row_counter++;
			cols_info->files_done++;
			col++;
			if (cols_info->files_done == cols_info->files_count_actual)
				break;
		}
		row++;
		ft_printf("\n");
	}
}

static void free_matrix(t_cols *cols, char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		ft_strdel(&matrix[i]);
		i++;
	}
	free(matrix);
	ft_memdel((void**)&cols);
}

void		print_column(t_file *files, const t_flags *flags)
{
	t_cols 			*cols_info;
	t_matrix		**matrix;
	int 			refuse_files_per_col;
	int 			rows;

	cols_info = init_cols_info(files);
	matrix = make_matrix(cols_info->files_count_actual, files, flags);
	rows = cols_info->files_count_actual / cols_info->cols;
	refuse_files_per_col = cols_info->files_count_actual % cols_info->cols;
	rows = refuse_files_per_col ? rows + 1 : rows;
	print_block(cols_info, matrix, rows);
	free_matrix(cols_info, matrix);
}
