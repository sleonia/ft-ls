#include "print/print.h"
#include "types.h"
#include <sys/ioctl.h>

void	print_column(const t_file *files, const t_flags *flags)
{
	int				term_width;
	int				cols;
	struct ttysize	ts;
	int bad_cols = 0;
	//char			matrix[files->origin->conf->count][files->origin->conf->name_len];
	int max_file_len = files->origin ? files->origin->conf->name_len : files->conf->name_len;
	int files_count_actual = files->origin ? files->origin->conf->count_actual : files->conf->count_actual;///////I NEED THIS AS IF -a WAS TRUE EVEN IF ITS NOT
	int files_count_total = files->origin ? files->origin->conf->count_total : files->conf->count_total;
	char			matrix[files_count_actual][max_file_len];////norm error here

	ft_memset(matrix, '\0', sizeof(matrix));
	ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
	term_width = ts.ts_cols;

	///test
//	term_width = 80;//SET WIDTH HERE FOR DEBUGGER
	///end of test
	cols = term_width / (max_file_len + 4); ////amount of columns

	t_file *tmp = (t_file *)files->files_inside;
	for (int i = 0; i < files_count_actual && tmp; i++)
	{
		if (flags->a || (!flags->a && tmp->name[0] != '.'))
			ft_strcpy(matrix[i], tmp->name);
		else (i--);
		tmp = tmp->next;
	}


	int index = 0;////index for printing
	int 			file_in_row_counter = 0;///files num in curr row
	int 			files_done = 0;////files already printed
	int 			row = 0;///curr row
	int 			col = 0;////curr col
	files_done = 0;
	row = 0;
	file_in_row_counter = 0;
	int normal_files_per_col = files_count_total / cols;
	int good_rows = 0;
	int bad_rows = 0;///this will be the amount of rows with not max amount of files
	/*here i will find amount of good rows that i need to print
	 *
	 */
	int refuse_files_per_col = files_count_actual % cols;
	if (refuse_files_per_col)
	{
		while (refuse_files_per_col)
		{
			bad_rows++;
			refuse_files_per_col = files_count_actual & cols - bad_rows;
		}
	}
	good_rows = files_count_total / cols;
	refuse_files_per_col = files_count_actual % cols;

	if (refuse_files_per_col)
	{
		good_rows = good_rows - bad_rows;
		bad_cols = (files_count_actual - cols * good_rows) / bad_rows;
		int bad_files_per_col = bad_cols;
	}
	int normal_rows_done = 0;//////////checks wether we are doing an incomplete row


	int index_file_counter = flags->a ? files_count_total : files_count_actual;

	while (files_done < files_count_actual)
	{

		///first we print good rows

		while (good_rows)
		{
			col = 1;
			file_in_row_counter = 0;
			while (/*col < (cols + 1)*/file_in_row_counter < cols)
			{
//				normal_rows_done = (index_file_counter - files_done) < refuse_files_per_col ? refuse_files_per_col : 0;
				index = row + (col - 1)  * (normal_files_per_col);

				if (flags->a || (!flags->a && matrix[index][0] != '.'))
				{
					ft_printf("%-*s ", max_file_len + 1, matrix[index]);////wrong width?
					file_in_row_counter++;

				}
				files_done++;
				col++;
			}
			row++;
			ft_printf("\n");
			good_rows--;
		}

		/////now we print other rows
		while (bad_rows)
		{
			col = 1;
			file_in_row_counter = 0;
			while (file_in_row_counter < bad_cols)
			{
				index = row + (col - 1)  * (normal_files_per_col/* - normal_rows_done*/);
				if (flags->a || (!flags->a && matrix[index][0] != '.'))
				{
					ft_printf("%-*s ", max_file_len + 1, matrix[index]);////wrong width?
					file_in_row_counter++;

				}
				files_done++;
				col++;
			}
			row++;
			ft_printf("\n");
			bad_rows--;

		}


	}

/*	for (int i = 0; i < files->origin->conf->count; i++) {
		printf("%s\n", matrix[i]);
	}*/
}