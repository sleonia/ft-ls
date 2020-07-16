#include "output/output.h"
#include "types.h"
#include <sys/ioctl.h>

//void		print_column(const t_file *file, const t_flags *flags,
//						const bool is_next, const t_conf *conf)
//{
//	int cols;
//	int lines;

//	struct ttysize ts;
//	ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
//	cols = ts.ts_cols;
//	lines = ts.ts_lines;
//	//printf("Terminal is %dx%d\n", cols, lines);
//}