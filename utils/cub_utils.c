/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:54:17 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/29 18:26:34 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

int		free_2d(t_str *str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		ft_free(str[i++]);
	free(str);
	return (SUCCESS);
}

int		ft_strlen_2d(t_str *str)
{
	int 	i;

	i = 0;
	while (str && str[i] != NULL)
		i++;
	return (i);
}

t_str	to_lowercase(t_str str)
{
    int i;
    t_str new_str;

    i = -1;
    new_str = ft_strdup(str);
    while (new_str && new_str[++i])
        if (new_str[i] >= 'A' && new_str[i] <= 'Z')
            new_str[i] = new_str[i] + 32;
    return (new_str);
}

void	draw(t_img *canvas, int x, int y, int color)
{
    canvas->data[y * canvas->width + x] = color;
}

char	value_at(t_cub *cub, int x, int y)
{
	if ((y >= 0 && y < cub->rows_nb) && (x >= 0 && x < cub->map[y].columns))
		return (cub->map[y].row[x]);
	return (' ');
}

char	value_at_pos(t_cub *cub, int x, int y)
{
	return (value_at(cub, floorf(x / TILE_SIZE), floorf(y / TILE_SIZE)));
}

t_bool	is_wall(t_cub *cub, float x, float y)
{
	const int	i = x / TILE_SIZE;
	const int	j = y / TILE_SIZE;
	return (value_at(cub, i, j) == '1' ||
			value_at(cub, i, j) == ' ');
}

t_bool	is_sprite(t_cub *cub, float x, float y)
{
	const int	i = x / TILE_SIZE;
	const int	j = y / TILE_SIZE;
	return (ft_strnchar("234", value_at(cub, i, j)));
}

float	normalize_rad(float angle)
{
	const float two_pi = 2 * M_PI;

	angle = remainderf(angle, two_pi);
	if (angle < 0)
		angle += two_pi;
	return (angle);
}

float	get_distance(t_cub *cub, float x, float y)
{
	return (sqrtf(POW(x - cub->cam.x) + POW(y - cub->cam.y)));
}

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
	off[X] = (int)(cub->ray[x].hitver ? cub->ray[x].hit[Y] : cub->ray[x].hit[X]) % cub->txt[img].width;
	off[Y] = vertoff * (cub->txt[img].height / stripe->height);
	off[X] = off[X] < 0 ? 0 : off[X];
	off[Y] = off[Y] < 0 ? 0 : off[Y];
	return (cub->txt[img].data[(off[Y] * cub->txt[img].width) + off[X]]);
}
