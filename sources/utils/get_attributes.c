#include "utils.h"
#include <sys/xattr.h>
#include <sys/acl.h>

char		get_attributes(const char *name)
{
	char		symb;
	acl_t		acl;
	acl_entry_t dummy;
	ssize_t		xattr;

	symb = ' ';
	acl = acl_get_link_np(name, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1) {
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(name, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		symb = '@';
	else if (acl != NULL)
		symb = '+';
	return (symb);
}
