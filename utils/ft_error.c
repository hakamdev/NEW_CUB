#include "../include/cubengine.h"

int		ft_clean(t_cub *cub, int return_code)
{
	return (return_code);
}

int		ft_perror(t_str msg, int return_code)
{
	int		len;

	len = ft_strlen(msg);
	write(2, msg, len);
	write(2, "\n\n", 2);
	exit(return_code);
}