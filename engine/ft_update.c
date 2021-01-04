/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:53:02 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:55:34 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	update_camera(t_cub *cub)
{
	float next_x;
	float next_y;

	next_x = cub->cam.x + cub->cam.mov_spd *
				cub->cam.mov_dir *
				cosf(cub->cam.ang + cub->cam.side_ang);
	next_y = cub->cam.y + cub->cam.mov_spd *
				cub->cam.mov_dir *
				sinf(cub->cam.ang + cub->cam.side_ang);
	cub->cam.ang += (cub->cam.rot_spd * cub->cam.rot_dir);
	if (!is_wall(cub, next_x, cub->cam.y) &&
		!is_sprite(cub, next_x, cub->cam.y))
		cub->cam.x = next_x;
	if (!is_wall(cub, cub->cam.x, next_y) &&
		!is_sprite(cub, cub->cam.x, next_y))
		cub->cam.y = next_y;
}

void	update_rays(t_cub *cub)
{
	int			i;
	float		start_ang;
	const float	ang_step = cub->fov / cub->cnvs.width;
	t_ray		*rrr;

	i = -1;
	start_ang = cub->cam.ang - (cub->fov / 2);
	while (++i < cub->cnvs.width)
	{
		cub->ray[i].ang = normalize_rad(start_ang);
		update_ray(cub, &cub->ray[i]);
		start_ang += ang_step;
		rrr = &cub->ray[i];
	}
}

void	update_rendering_walls(t_cub *cub)
{
	int			i;
	int			j;
	t_wdata		strp;
	const float	pplane_dist = (cub->cnvs.width / 2.0F) / tanf((cub->fov) / 2);
	float		corr_dist;

	i = -1;
	while (++i < cub->cnvs.width)
	{
		corr_dist = cub->ray[i].dist * cosf(cub->ray[i].ang - cub->cam.ang);
		strp.height = TL_SIZE / corr_dist * pplane_dist;
		strp.top = ((float)cub->cnvs.height / 2) - (strp.height / 2);
		strp.bttm = ((float)cub->cnvs.height / 2) + (strp.height / 2);
		strp.top = strp.top < 0 ? 0 : strp.top;
		strp.bttm = strp.bttm > cub->cnvs.height ? cub->cnvs.height : strp.bttm;
		render_ciel_stripe(cub, 0, strp.top, i);
		render_wall_stripe(cub, &strp, i);
		render_flor_stripe(cub, strp.bttm, cub->cnvs.height, i);
	}
}

void	update_rendering_sprites(t_cub *cub)
{
	int			i;
	int			off[2];
	const float	pplane_dist = (cub->cnvs.width / 2.0F) / tanf((cub->fov) / 2);

	i = -1;
	while (++i < cub->sprs_nb)
	{
		cub->spr[i].dist = ft_distance(cub, cub->spr[i].x, cub->spr[i].y);
		cub->spr[i].ang = atan2f(cub->spr[i].y - cub->cam.y,
		cub->spr[i].x - cub->cam.x);
		cub->spr[i].ang = normalize_spr(cub, cub->spr[i].ang);
		cub->spr[i].scale = cub->cnvs.width * (float)TL_SIZE / cub->spr[i].dist;
		cub->spr[i].offy = (cub->cnvs.height / 2.0F) - (cub->spr[i].scale / 2);
		cub->spr[i].offx = ((ft_deg(cub->spr[i].ang) - ft_deg(cub->cam.ang))
		* cub->cnvs.width) / 60
		+ ((cub->cnvs.width / 2.0F) - (cub->spr[i].scale / 2));
	}
	sort_sprites(cub);
	i = -1;
	while (++i < cub->sprs_nb)
	{
		off[X] = cub->spr[i].offx;
		off[Y] = cub->spr[i].offy;
		render_sprite(cub, i, off);
	}
}
