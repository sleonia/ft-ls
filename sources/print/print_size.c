#include "types.h"
#include "utils.h"
#include <sys/types.h>

void	print_size(const struct stat *stat_, unsigned size)
{
	if (S_ISCHR(stat_->st_mode) || S_ISBLK(stat_->st_mode))
		ft_printf("%*d, %*d ", size, major(stat_->st_rdev), size, minor(stat_->st_rdev));
	else
		ft_printf("%*lld ", size, stat_->st_size);
}
