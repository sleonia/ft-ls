#include "types.h"
#include "utils/utils.h"

/*!
** \file
** \brief Get type of file
** \return	one of "-dcbsl?"
*/

int			get_type(mode_t mode) {
	mode &= S_IFMT;
	if (mode == S_IFCHR)
		return (Character_device);
	if (mode == S_IFDIR)
		return (Directory);
	if (mode == S_IFBLK)
		return (Block_device);
	if (mode == S_IFREG)
		return (Regular);
	if (mode == S_IFLNK)
		return (Link);
	if (mode == S_IFSOCK)
		return (Socket);
	return (Unknown);
}
