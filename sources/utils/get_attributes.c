/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:32:03 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 15:40:55 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <sys/xattr.h>
#include <sys/acl.h>

/*
** \file
** \brief Return attributes:
**			@ or +
**
**	- drwxrwxr-x+
**	- lrwxr-xr-x@
*/

char		get_attributes(const char *name)
{
	char		symb;
	acl_t		acl;
	acl_entry_t dummy;
	ssize_t		xattr;

	symb = ' ';
	acl = acl_get_link_np(name, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
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
