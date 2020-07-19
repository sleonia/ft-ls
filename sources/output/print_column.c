#include "output/output.h"
#include "types.h"
#include <sys/ioctl.h>

static	char		**create_matrix(int file_count_in_col)
{
	char			**matrix;

	if (!(matrix = (char **)ft_memalloc(sizeof(char *) * file_count_in_col + 1)))
		return (NULL);
	return (matrix);
}

void		print_column(const t_file *file, const t_flags *flags,
						bool is_next, const t_conf *conf)
{
	//int				term_width;
	//int				cols;
	//struct ttysize	ts;
	//char			**matrix;


	//ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
	//term_width = ts.ts_cols;
	//printf("Terminal is %d\nCount %d\n", term_width, conf->count);
	//cols = term_width / (conf->name_len + 1);
	//if (!(matrix = create_matrix()))
		//return ; //maybe exit MALLOC ERROR
}