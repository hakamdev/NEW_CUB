#include "../include/cubengine.h"

void		check_map_element(t_cub *cub, int i, int j)
{
	int		m;
	int		n;

	n = -2;
	while (++n <= 1)
	{
		m = -2;
		while (++m <= 1)
			if (value_at(cub, i + m, j + n) == ' ')
				ft_perror("Map is not properly closed!", ft_clean(cub, ERROR));
	}
}

void		check_map(t_cub *cub)
{
	int		i;
	int		j;

	j = -1;
	while (++j < cub->rows_nb)
	{
		i = -1;
		while (++i < cub->map[j].columns)
		{
			if (ft_strnchar("02NEWS", (value_at(cub, i, j))))
				check_map_element(cub, i, j);
			else if (!ft_strnchar("012NEWS ", value_at(cub, i, j)))
				ft_perror("Forbidden Characters in Map!", ft_clean(cub, ERROR));
		}
	}
}
