#include "print/print.h"
#include "types.h"
#include <sys/ioctl.h>


void	print_column(const t_file *files, const t_flags *flags, const t_conf *conf)
{
	int				term_width;
	int				cols;
	struct ttysize	ts;
	char			matrix[conf->count][conf->name_len];

	ft_memset(matrix, '\0', sizeof(matrix));
	ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
	term_width = ts.ts_cols;
	//printf("Terminal is %d\nCount %d\n", term_width, conf->count);
	cols = term_width / (conf->name_len + 1);

	t_file *tmp = (t_file *)files->files_inside;
	for (int i = 0; i < conf->count && tmp; i++) {
		ft_strcpy(matrix[i], tmp->name);
		tmp = tmp->next;
	}

	for (int i = 0; i < conf->count; i++) {
		printf("%s\n", matrix[i]);
	}
}