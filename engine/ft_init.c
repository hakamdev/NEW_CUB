/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:52:03 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/28 18:18:19 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void		init_cam(t_cub *cub)
{
	cub->cam.mov_dir =		0;
	cub->cam.rot_dir =		0;
	cub->cam.side_ang = 	0.0F;
	cub->cam.mov_spd = 		(TILE_SIZE / 20.0F);
	cub->cam.rot_spd =		RAD(1.0F);
}

void		init_cub(t_cub *cub)
{
	int		i;

	i =						-1;
	cub->cam.x =			-1;
	cub->cam.y =			-1;
	cub->read_nb = 			0;
	cub->sprs_nb = 			0;
	WIN_WIDTH = 			0;
	WIN_HEIGHT = 			0;
	cub->map = 				NULL;
	cub->spr = 				NULL;
	cub->ray = 				NULL;
	cub->line =				NULL;
	cub->parts =			NULL;
	cub->screenshot = 		false;
	while (++i < 6)
		cub->txt[i].path =	NULL;
}

void		init_mlx(t_cub *cub)
{
	if (!(cub->mlx = mlx_init()))
		ft_perror( "Error: Failed to initialize mlx!", ft_clean(cub, ERROR));
	if (!(cub->window = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, CUBTITLE)))
		ft_perror( "Error: Failed to initialize Window!", ft_clean(cub, ERROR));
	if (!(cub->cnvs.img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT)))
		ft_perror( "Error: Failed to initialize Canvas!", ft_clean(cub, ERROR));
	cub->cnvs.data = (int *)mlx_get_data_addr(cub->cnvs.img, &cub->cnvs.bpp,
											&cub->cnvs.sl, &cub->cnvs.end);
}

int			init_sprite(t_cub *cub, int i, int j)
{
	int			index;
	t_sprite	tmp_spr;
	t_sprite	*tmp_sprs;

	index = 0;
    tmp_sprs = cub->spr;
	if (!(cub->spr = (t_sprite *)malloc(sizeof(t_sprite) * ++(cub->sprs_nb))))
		return (ERROR);
	if (cub->sprs_nb > 0)
	{
		index = -1;
		while (++index < cub->sprs_nb - 1)
            cub->spr[index] = tmp_sprs[index];
		free(tmp_sprs);
	}
	tmp_spr.x = (i + 0.5f) * TILE_SIZE;
	tmp_spr.y = (j + 0.5f) * TILE_SIZE;
	cub->spr[index] = tmp_spr;
	return (SUCCESS);
}

void		init_sprites(t_cub *cub)
{
	int		i;
	int		j;

	j = -1;
	while (++j < cub->rows_nb)
	{
		i = -1;
		while (++i < cub->map[j].columns)
			if (value_at(cub, i, j) == '2')
				if (IS_ERROR(init_sprite(cub, i, j)))
					ft_perror("Error: Failed to allocate memory!",
						ft_clean(cub, ERROR));
	}
}

void		init_ray(t_ray *ray)
{
		ray->dir[SOUTH] = (ray->ang > 0.0F) && (ray->ang < M_PI);
		ray->dir[EAST] = (ray->ang < 0.5F * M_PI) || (ray->ang > 1.5F * M_PI);
		ray->dir[NORTH] = !(ray->dir[SOUTH]);
		ray->dir[WEST] = !(ray->dir[EAST]);
}

void		init_rays(t_cub *cub)
{
	int		i;

	i = -1;
	if (!(cub->ray = malloc(sizeof(t_ray) * WIN_WIDTH)))
		ft_perror("Error: Failed to allocate memory!", ft_clean(cub, ERROR));
	while (++i < WIN_WIDTH)
	{
		cub->ray[i].dist = 0.0F;
		cub->ray[i].hit[X] = 0.0F;
		cub->ray[i].hit[Y] = 0.0F;
		cub->ray[i].hitver = false;
		init_ray(&cub->ray[i]);
	}
}

void		init_game(t_cub *cub, int ac, t_str *av)
{
	init_cub(cub);
	init_cam(cub);
	check_arguments(cub, ac, av);
    read_file(cub, av[1]);
	init_mlx(cub);
	init_images(cub);
	init_rays(cub);
	init_sprites(cub);
}




