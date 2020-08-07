#include "print/print.h"
#include "types.h"
#include <sys/ioctl.h>

void	print_column(const t_file *files, const t_flags *flags)
{
	int				term_width;
	int				cols;
	struct ttysize	ts;
	//char			matrix[files->origin->conf->count][files->origin->conf->name_len];
	int max_file_len = files->origin ? files->origin->conf->name_len : files->conf->name_len;
	int files_count = files->origin ? files->origin->conf->count : files->conf->count;///////I NEED THIS AS IF -a WAS TRUE EVEN IF ITS NOT
	char			matrix[files_count][max_file_len];////norm error here

	ft_memset(matrix, '\0', sizeof(matrix));
	ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
	term_width = ts.ts_cols;

	///test
	//term_width = 100;SET WIDTH HERE FOR DEBUGGER
	///end of test
	cols = term_width / (max_file_len + 4); ////amount of columns

	t_file *tmp = (t_file *)files->files_inside;
	for (int i = 0; i < files_count && tmp; i++)
	{
		ft_strcpy(matrix[i], tmp->name);
		tmp = tmp->next;
	}


	int index = 0;////index for printing
	int 			file_in_row_counter = 0;///files num in curr row
	int 			files_done;////files already printed
	int 			row;///curr row
	int 			col;////curr col
	files_done = 0;
	row = 0;
	file_in_row_counter = 0;
	int normal_files_per_col = files_count / cols;
	int refuse_files_per_col = files_count % cols;
	int normal_rows_done = 0;

	while (files_done < files_count)
	{

		col = 1;
		while (col < (cols + 1))
		{
			normal_rows_done = (files_count - files_done) < refuse_files_per_col ? refuse_files_per_col : 0;
			index = row + (col - 1)  * (normal_files_per_col - normal_rows_done);

			ft_printf("%-*s ", max_file_len + 1, matrix[index]);
			col++;
			files_done++;
		}
		row++;
		printf("\n");

	}

/*	for (int i = 0; i < files->origin->conf->count; i++) {
		printf("%s\n", matrix[i]);
	}*/
}