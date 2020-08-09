#include "print/print.h"
#include "types.h"


static char **make_matrix(int files_count, t_file *files, t_flags *flags)
{
	char 	**matrix;
	int 	i;
	t_file 	*tmp;

	matrix = (char**)ft_memalloc(sizeof(char*) * files_count);
	i = 0;
	tmp = files->files_inside;
	while (i < files_count && tmp)
	{
		if (flags->a || (!flags->a && tmp->name[0] != '.'))
		{
			matrix[i] = ft_strdup(tmp->name);
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
	cols_info->max_file_len = file->origin ? file->origin->conf->name_len : file->conf->name_len;
	cols_info-> files_count_actual = file->origin ? file->origin->conf->count_actual : file->conf->count_actual;
	cols_info->files_count_total = file->origin ? file->origin->conf->count_total : file->conf->count_total;
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

static void print_block(t_cols *cols_info, char **matrix, int rows)
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
		//		index -= cols_info->cols;
				index -= cols_info->normal_files_per_col;
				index += refuse;
			}

			////test index
//			ft_printf("index is : |%d| ", index);
			///end of test index
			ft_printf("%-*s ", cols_info->max_file_len + 1, matrix[index]);
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

static void test_matrix_delete_me(char **matrix, int filenum)
{
	int i = 0;
	while (i < filenum)
	{
		ft_printf("index = |%d| matrix = |%s|\n", i, matrix[i]);
		i++;
	}
}

void		print_column(t_file *files, const t_flags *flags)
{
	t_cols 			*cols_info;
	char			**matrix;
	int 			refuse_files_per_col;
	int 			rows;

	cols_info = init_cols_info(files);
	matrix = make_matrix(cols_info->files_count_actual, files, flags);
	rows = cols_info->files_count_actual / cols_info->cols;
	refuse_files_per_col = cols_info->files_count_actual % cols_info->cols;
	rows = refuse_files_per_col ? rows + 1 : rows;
	///del funct below
	test_matrix_delete_me(matrix, cols_info->files_count_actual);
	print_block(cols_info, matrix, rows);
}
