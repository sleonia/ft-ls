#include "ftls.h"

int ft_error()
{
	char *error = strerror(errno);
	perror(error);
	return (-1);
	////deal with it later;
}