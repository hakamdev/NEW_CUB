#include "../include/cubengine.h"

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
	while (++i < 6)
		cub->txt[i].path =	NULL;
}