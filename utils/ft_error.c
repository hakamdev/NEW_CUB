/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:54:41 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 12:53:59 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	ft_destroy_images(t_cub *cub)
{
	int		i;

		if (cub->cnvs.img != NULL)
	{
		mlx_destroy_image(cub->mlx, cub->cnvs.img);
		ft_free(cub->cnvs.path);
		free(cub->cnvs.data);
	}
	i = -1;
	while (++i < 6)
		if (cub->txt[i].img != NULL)
		{
		mlx_destroy_image(cub->mlx, cub->txt[i].img);
		ft_free(cub->txt[i].path);
		free(cub->txt[i].data);
		}
}

int		ft_clean(t_cub *cub, int return_code)
{
	int		i;

	i = -1;
	if (cub->map != NULL)
	{
		while (++i < cub->rows_nb)
			ft_free(cub->map[i].row);
		free(cub->map);
	}
	if (cub->ray != NULL)
		free(cub->ray);
	if (cub->spr != NULL)
		free(cub->spr);
	ft_destroy_images(cub);
	if (cub->window != NULL)
	{
		mlx_destroy_window(cub->mlx, cub->window);
		free(cub->mlx);
	}
	return (return_code);
}

void	ft_perror(t_str msg, int return_code)
{
	int len;

	len = ft_strlen(msg);
	write(2, "\033[0;31m", 8);
	write(2, "Error: ", 7);
	write(2, msg, len);
	write(2, "\n\n", 2);
	exit(return_code);
}
