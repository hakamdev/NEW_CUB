#include "../include/cubengine.h"

void	ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}