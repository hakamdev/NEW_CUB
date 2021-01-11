/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:51:27 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/06 14:51:11 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	set_camera_rotation(t_cub *cub, char direction)
{
	if (direction == 'N')
		cub->cam.ang = ft_rad(270);
	else if (direction == 'W')
		cub->cam.ang = ft_rad(180);
	else if (direction == 'S')
		cub->cam.ang = ft_rad(90);
	else if (direction == 'E')
		cub->cam.ang = ft_rad(0);
}

t_bool	is_camera(t_cub *cub, int i, int j)
{
	if (value_at(cub, i, j) == 'N' ||
		value_at(cub, i, j) == 'S' ||
		value_at(cub, i, j) == 'W' ||
		value_at(cub, i, j) == 'E')
		return (true);
	return (false);
}

void	check_camera(t_cub *cub)
{
	t_bool		cam_exists;
	int			i;
	int			j;

	j = -1;
	cam_exists = false;
	while (++j < cub->rows_nb)
	{
		i = -1;
		while (++i < cub->map[j].columns)
		{
			if (is_camera(cub, i, j))
			{
				if (cam_exists)
					ft_perror("Only one Player is required!",
					ft_clean(cub, ERR));
				cam_exists = true;
				set_camera_rotation(cub, value_at(cub, i, j));
				cub->cam.x = (i + 0.5F) * TL_SIZE;
				cub->cam.y = (j + 0.5F) * TL_SIZE;
			}
		}
	}
	if (!cam_exists)
		ft_perror("Player doesn't exist in Map!", ft_clean(cub, ERR));
}
