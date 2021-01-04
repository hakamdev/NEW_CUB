/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:51:44 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:23:22 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

int		event_key_pressed(int key, t_cub *cub)
{
	if (key == 53)
		event_exit(cub);
	if (key == 13 || key == 119)
		cub->cam.mov_dir = 1;
	if (key == 1 || key == 115)
		cub->cam.mov_dir = -1;
	if (key == 124 || key == 65363)
		cub->cam.rot_dir = 1;
	if (key == 123 || key == 65361)
		cub->cam.rot_dir = -1;
	if (key == 0 || key == 97)
	{
		cub->cam.mov_dir = 1;
		cub->cam.side_ang = ft_rad(-90.0F);
	}
	if (key == 2 || key == 100)
	{
		cub->cam.mov_dir = 1;
		cub->cam.side_ang = ft_rad(90.0F);
	}
	return (SUCCESS);
}

int		event_key_released(int key, t_cub *cub)
{
	if (key == 13 || key == 119)
		cub->cam.mov_dir = 0;
	if (key == 1 || key == 115)
		cub->cam.mov_dir = 0;
	if (key == 124 || key == 65363)
		cub->cam.rot_dir = 0;
	if (key == 123 || key == 65361)
		cub->cam.rot_dir = 0;
	if (key == 0 || key == 97)
	{
		cub->cam.mov_dir = 0;
		cub->cam.side_ang = ft_rad(0.0F);
	}
	if (key == 2 || key == 100)
	{
		cub->cam.mov_dir = 0;
		cub->cam.side_ang = ft_rad(0.0F);
	}
	return (SUCCESS);
}

int		event_game_loop(t_cub *cub)
{
	update_camera(cub);
	update_rays(cub);
	update_rendering_walls(cub);
	update_rendering_sprites(cub);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->cnvs.img, 0, 0);
	return (SUCCESS);
}

int		event_exit(t_cub *cub)
{
	exit(ft_clean(cub, SUCCESS));
}
