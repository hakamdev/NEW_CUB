#include "../include/cubengine.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}