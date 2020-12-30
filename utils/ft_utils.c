/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:54:17 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/30 17:06:34 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

t_bool	is_read_complete(t_cub *cub)
{
	return (cub->checker.resolution && cub->checker.txt_north &&
			cub->checker.txt_south && cub->checker.txt_west &&
			cub->checker.txt_east && cub->checker.txt_sprite &&
			cub->checker.clr_ceiling && cub->checker.clr_floor);
}

t_str	extract_value(t_str line)
{
	int start;
	int end;

	start = 0;
	end = ft_strlen(line) - 1;
	while (line[start] && line[start] == ' ')
		start++;
	while (line[start] && line[start] != ' ')
		start++;
	while (line[start] && line[start] == ' ')
		start++;
	while (end > 0 && line[end] == ' ')
		end--;
	line[end + 1] = '\0';
	return (ft_strdup(&line[start]));
}

t_bool	is_wall(t_cub *cub, float x, float y)
{
	const int	i = x / TILE_SIZE;
	const int	j = y / TILE_SIZE;

	return (value_at(cub, i, j) == '1' ||
			value_at(cub, i, j) == ' ');
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
