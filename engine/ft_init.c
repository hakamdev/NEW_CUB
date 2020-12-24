#include "../include/cubengine.h"

void		init_cam(t_cub *cub)
{
	cub->cam.mov_dir =		0;
	cub->cam.rot_dir =		0;
	cub->cam.side_ang = 	0.0F;
	cub->cam.mov_spd = 		(TILE_SIZE / 20.0F);
	cub->cam.rot_spd =		RAD(0.3F);
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
	cub->errno =			NULL;
	cub->fname =			NULL;
	cub->screenshot = 		false;
	cub->map = 				NULL;
	cub->spr = 				NULL;
	cub->ray = 				NULL;
	init_cam(cub);
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


