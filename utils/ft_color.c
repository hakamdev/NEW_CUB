/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:46:21 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/03 17:15:56 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

int		color_rgb_to_hex(t_color clr)
{
	return ((clr.r * POW(256)) + (clr.g * 256) + clr.b);
}

int		get_color_from_txt(t_cub *cub, t_wdata *stripe, int pos[2], int img)
{
	int			off[2];
	float		vertoff;
	const int	x = pos[X];
	const int	y = pos[Y];

	vertoff = y + (stripe->height - WIN_HEIGHT) / 2;
	off[X] = (int)(cub->ray[x].hitver ? cub->ray[x].hit[Y]
	: cub->ray[x].hit[X]) % cub->txt[img].width;
	off[Y] = vertoff * (cub->txt[img].height / stripe->height);
	off[X] = off[X] < 0 ? 0 : off[X];
	off[Y] = off[Y] < 0 ? 0 : off[Y];
	return (cub->txt[img].data[(off[Y] * cub->txt[img].width) + off[X]]);
}

t_color	color_hex_to_rgb(unsigned int color)
{
	t_color		out_clr;

	out_clr.r = color / POW(256);
	out_clr.g = (color - (out_clr.r * POW(256))) / 256;
	out_clr.b = color - (out_clr.r * POW(256) + out_clr.g * 256);
	return (out_clr);
}