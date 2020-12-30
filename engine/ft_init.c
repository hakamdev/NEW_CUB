/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:52:03 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/30 16:43:10 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	init_read_check(t_cub *cub)
{
	cub->checker.resolution = false;
	cub->checker.txt_north = false;
	cub->checker.txt_south = false;
	cub->checker.txt_west = false;
	cub->checker.txt_east = false;
	cub->checker.txt_sprite = false;
	cub->checker.clr_ceiling = false;
	cub->checker.clr_floor = false;
	cub->checker.is_map = false;
}

void	init_cam(t_cub *cub)
{
	cub->cam.mov_dir = 0;
	cub->cam.rot_dir = 0;
	cub->cam.side_ang = 0.0F;
	cub->cam.mov_spd = (TILE_SIZE / 20.0F);
	cub->cam.rot_spd = RAD(1.0F);
}

void	init_cub(t_cub *cub)
{
	int		i;

	i = -1;
	cub->cam.x = -1;
	cub->cam.y = -1;
	cub->read_nb = 0;
	cub->sprs_nb = 0;
	WIN_WIDTH = 0;
	WIN_HEIGHT = 0;
	cub->map = NULL;
	cub->spr = NULL;
	cub->ray = NULL;
	cub->line = NULL;
	cub->parts = NULL;
	cub->screenshot = false;
	while (++i < 6)
		cub->txt[i].path = NULL;
}

void	init_mlx(t_cub *cub)
{
	if (!(cub->mlx = mlx_init()))
		ft_perror("Error: Failed to initialize mlx!", ft_clean(cub, ERR));
	if (!(cub->window = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT,
		CUBTITLE)))
		ft_perror("Error: Failed to initialize Window!", ft_clean(cub, ERR));
	if (!(cub->cnvs.img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT)))
		ft_perror("Error: Failed to initialize Canvas!", ft_clean(cub, ERR));
	cub->cnvs.data = (int *)mlx_get_data_addr(cub->cnvs.img, &cub->cnvs.bpp,
											&cub->cnvs.sl, &cub->cnvs.end);
}

void	init_game(t_cub *cub, int ac, t_str *av)
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
