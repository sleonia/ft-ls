#include "print/print.h"
#include "types.h"
#include <sys/ioctl.h>

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