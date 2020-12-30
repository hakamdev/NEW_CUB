/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:54:17 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/30 16:04:12 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

t_bool	is_wall(t_cub *cub, float x, float y)
{
	const int	i = x / TILE_SIZE;
	const int	j = y / TILE_SIZE;

	return (value_at(cub, i, j) == '1' ||
			value_at(cub, i, j) == ' ');
}

t_str	to_lowercase(t_str str)
{
	int		i;
	t_str	new_str;

	i = -1;
	new_str = ft_strdup(str);
	while (new_str && new_str[++i])
		if (new_str[i] >= 'A' && new_str[i] <= 'Z')
			new_str[i] = new_str[i] + 32;
	return (new_str);
}

char	value_at(t_cub *cub, int x, int y)
{
	if ((y >= 0 && y < cub->rows_nb) && (x >= 0 && x < cub->map[y].columns))
		return (cub->map[y].row[x]);
	return (' ');
}

float	normalize_rad(float angle)
{
	const float two_pi = 2 * M_PI;

	angle = remainderf(angle, two_pi);
	if (angle < 0)
		angle += two_pi;
	return (angle);
}

float	get_distance(t_cub *cub, float x, float y)
{
	return (sqrtf(POW(x - cub->cam.x) + POW(y - cub->cam.y)));
}
