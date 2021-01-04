/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:54:17 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:54:50 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

t_bool	is_err(int val)
{
	return (val == ERR);
}

t_bool	is_succ(int val)
{
	return (val == SUCCESS);
}

t_bool	is_wall(t_cub *cub, float x, float y)
{
	const int	i = x / TL_SIZE;
	const int	j = y / TL_SIZE;

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
