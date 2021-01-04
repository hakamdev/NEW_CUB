/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:52:22 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:54:50 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	hori_collision(t_cub *cub, t_rdata *h, t_ray *r)
{
	h->dist = INT32_MAX;
	h->inter[Y] = floorf(cub->cam.y / (float)TL_SIZE) * TL_SIZE;
	h->inter[Y] += r->dir[SOUTH] ? TL_SIZE : 0;
	h->inter[X] = cub->cam.x + (h->inter[Y] - cub->cam.y) / tanf(r->ang);
	h->step[Y] = TL_SIZE;
	h->step[Y] *= r->dir[NORTH] ? -1 : 1;
	h->step[X] = TL_SIZE / tanf(r->ang);
	h->step[X] *= (r->dir[WEST] && h->step[X] > 0.0F) ? -1 : 1;
	h->step[X] *= (r->dir[EAST] && h->step[X] < 0.0F) ? -1 : 1;
	h->hit[X] = h->inter[X];
	h->hit[Y] = h->inter[Y];
	while (h->hit[Y] >= 0.0F && h->hit[X] >= 0.0F)
	{
		if (is_wall(cub, h->hit[X],
		(r->dir[NORTH] ? h->hit[Y] - 1 : h->hit[Y])))
		{
			h->dist = ft_distance(cub, h->hit[X], h->hit[Y]);
			break ;
		}
		h->hit[X] += h->step[X];
		h->hit[Y] += h->step[Y];
	}
}

void	vert_collision(t_cub *cub, t_rdata *v, t_ray *r)
{
	v->dist = INT32_MAX;
	v->inter[X] = floorf(cub->cam.x / (float)TL_SIZE) * TL_SIZE;
	v->inter[X] += r->dir[EAST] ? TL_SIZE : 0;
	v->inter[Y] = cub->cam.y + (v->inter[X] - cub->cam.x) * tanf(r->ang);
	v->step[X] = TL_SIZE;
	v->step[X] *= r->dir[WEST] ? -1 : 1;
	v->step[Y] = TL_SIZE * tanf(r->ang);
	v->step[Y] *= (r->dir[NORTH] && v->step[Y] > 0.0F) ? -1 : 1;
	v->step[Y] *= (r->dir[SOUTH] && v->step[Y] < 0.0F) ? -1 : 1;
	v->hit[Y] = v->inter[Y];
	v->hit[X] = v->inter[X];
	while (v->hit[Y] >= 0.0F && v->hit[X] >= 0.0F)
	{
		if (is_wall(cub, (r->dir[WEST] ? v->hit[X] - 1 : v->hit[X]), v->hit[Y]))
		{
			v->dist = ft_distance(cub, v->hit[X], v->hit[Y]);
			break ;
		}
		v->hit[X] += v->step[X];
		v->hit[Y] += v->step[Y];
	}
}

void	update_ray(t_cub *cub, t_ray *ray)
{
	t_rdata		horizontal;
	t_rdata		vertical;

	init_ray(ray);
	hori_collision(cub, &horizontal, ray);
	vert_collision(cub, &vertical, ray);
	if (vertical.dist > horizontal.dist)
	{
		ray->hitver = false;
		ray->dist = horizontal.dist;
		ray->hit[X] = horizontal.hit[X];
		ray->hit[Y] = horizontal.hit[Y];
	}
	else
	{
		ray->hitver = true;
		ray->dist = vertical.dist;
		ray->hit[X] = vertical.hit[X];
		ray->hit[Y] = vertical.hit[Y];
	}
}

void	init_ray(t_ray *ray)
{
	ray->dir[SOUTH] = (ray->ang > 0.0F) && (ray->ang < M_PI);
	ray->dir[EAST] = (ray->ang < 0.5F * M_PI) || (ray->ang > 1.5F * M_PI);
	ray->dir[NORTH] = !(ray->dir[SOUTH]);
	ray->dir[WEST] = !(ray->dir[EAST]);
}

void	init_rays(t_cub *cub)
{
	int		i;

	i = -1;
	if (!(cub->ray = malloc(sizeof(t_ray) * cub->cnvs.width)))
		ft_perror("Error: Failed to allocate memory!", ft_clean(cub, ERR));
	while (++i < cub->cnvs.width)
	{
		cub->ray[i].dist = 0.0F;
		cub->ray[i].hit[X] = 0.0F;
		cub->ray[i].hit[Y] = 0.0F;
		cub->ray[i].hitver = false;
		init_ray(&cub->ray[i]);
	}
}
