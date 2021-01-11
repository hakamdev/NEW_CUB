/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:51:11 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/06 15:27:40 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	draw(t_img *canvas, int x, int y, int color)
{
	canvas->data[y * canvas->width + x] = color;
}

void	render_sprite(t_cub *cub, int id, int off[2])
{
	int			ax[2];
	int			r[2];
	int			clrindex;
	const float	ratio = cub->txt[SPR].width / cub->spr[id].scale;

	ax[X] = -1;
	while (++ax[X] < (int)cub->spr[id].scale)
	{
		if (off[X] + ax[X] < 0 || off[X] + ax[X] >= cub->cnvs.width)
			continue ;
		if (cub->ray[off[X] + ax[X]].dist <= cub->spr[id].dist)
			continue ;
		ax[Y] = -1;
		r[X] = (ax[X] * ratio);
		while (++ax[Y] < (int)cub->spr[id].scale)
		{
			if (off[Y] + ax[Y] < 0 || off[Y] + ax[Y] >= cub->cnvs.height)
				continue ;
			r[Y] = (ax[Y] * ratio);
			clrindex = (r[Y] * cub->txt[SPR].width) + r[X];
			if (cub->txt[SPR].data[clrindex] != cub->txt[SPR].data[0])
				draw(&cub->cnvs, off[X] + ax[X], off[Y] + ax[Y],
				cub->txt[SPR].data[clrindex]);
		}
	}
}

void	render_wall_stripe(t_cub *cub, t_wdata *stripe, int x)
{
	int		y;
	int		color;
	int		pos[2];

	y = stripe->top - 1;
	pos[X] = x;
	while (++y < stripe->bttm)
	{
		pos[Y] = y;
		if (cub->ray[x].hitver && cub->ray[x].dir[WEST])
			color = get_color_from_txt(cub, stripe, pos, EAST);
		else if (cub->ray[x].hitver && cub->ray[x].dir[EAST])
			color = get_color_from_txt(cub, stripe, pos, WEST);
		else if (!cub->ray[x].hitver && cub->ray[x].dir[NORTH])
			color = get_color_from_txt(cub, stripe, pos, SOUTH);
		else if (!cub->ray[x].hitver && cub->ray[x].dir[SOUTH])
			color = get_color_from_txt(cub, stripe, pos, NORTH);
		draw(&cub->cnvs, x, y, color);
	}
}

void	render_ciel_stripe(t_cub *cub, int ystart, int yend, int x)
{
	while (ystart < yend)
		draw(&cub->cnvs, x, ystart++, color_rgb_to_hex(cub->color[CIEL]));
}

void	render_flor_stripe(t_cub *cub, int ystart, int yend, int x)
{
	while (ystart < yend)
		draw(&cub->cnvs, x, ystart++, color_rgb_to_hex(cub->color[FLOOR]));
}
