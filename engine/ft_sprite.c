/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:52:56 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/06 14:52:27 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

t_bool	is_sprite(t_cub *cub, float x, float y)
{
	const int	i = x / TL_SIZE;
	const int	j = y / TL_SIZE;

	return (ft_strnchar("234", value_at(cub, i, j)));
}

float	normalize_spr(t_cub *cub, float angle)
{
	while (angle - cub->cam.ang > M_PI)
		angle -= 2 * M_PI;
	while (angle - cub->cam.ang < -M_PI)
		angle += 2 * M_PI;
	return (angle);
}

void	sort_sprites(t_cub *cub)
{
	int			i;
	int			j;
	int			sprs_nb;
	t_sprite	spr_tmp;

	i = -1;
	sprs_nb = cub->sprs_nb;
	while (++i < cub->sprs_nb)
	{
		j = -1;
		while (++j + 1 < sprs_nb)
			if (cub->spr[j].dist < cub->spr[j + 1].dist)
			{
				spr_tmp = cub->spr[j + 1];
				cub->spr[j + 1] = cub->spr[j];
				cub->spr[j] = spr_tmp;
			}
		--sprs_nb;
	}
}

int		init_sprite(t_cub *cub, int i, int j)
{
	int			index;
	t_sprite	tmp_spr;
	t_sprite	*tmp_sprs;

	index = 0;
	tmp_sprs = cub->spr;
	if (!(cub->spr = (t_sprite *)malloc(sizeof(t_sprite) * ++(cub->sprs_nb))))
		return (ERR);
	if (cub->sprs_nb > 0)
	{
		index = -1;
		while (++index < cub->sprs_nb - 1)
			cub->spr[index] = tmp_sprs[index];
		free(tmp_sprs);
	}
	tmp_spr.x = (i + 0.5f) * TL_SIZE;
	tmp_spr.y = (j + 0.5f) * TL_SIZE;
	cub->spr[index] = tmp_spr;
	return (SUCCESS);
}

void	init_sprites(t_cub *cub)
{
	int		i;
	int		j;

	j = -1;
	while (++j < cub->rows_nb)
	{
		i = -1;
		while (++i < cub->map[j].columns)
			if (value_at(cub, i, j) == '2')
				if (init_sprite(cub, i, j) == ERR)
					ft_perror("Failed to allocate memory!",
						ft_clean(cub, ERR));
	}
}
