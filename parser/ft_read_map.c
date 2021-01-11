/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:49:22 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/06 14:52:50 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	read_map(t_cub *cub)
{
	int		i;
	t_map	*tmap;

	cub->checker.is_map = true;
	if (cub->map == NULL)
	{
		if (!(cub->map = malloc(1 * sizeof(t_map))))
			ft_perror("Failed to allocate memory!", ft_clean(cub, ERR));
		cub->map[0].row = ft_strdup(cub->line);
		cub->map[0].columns = ft_strlen(cub->line);
		cub->rows_nb = 1;
		return ;
	}
	i = -1;
	tmap = cub->map;
	if (!(cub->map = malloc(++(cub->rows_nb) * sizeof(t_map))))
		ft_perror("Failed to allocate memory!", ft_clean(cub, ERR));
	while (++i < cub->rows_nb - 1)
		cub->map[i] = tmap[i];
	cub->map[i].row = ft_strdup(cub->line);
	cub->map[i].columns = ft_strlen(cub->line);
	free(tmap);
}
