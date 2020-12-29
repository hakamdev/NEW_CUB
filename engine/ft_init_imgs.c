/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:52:11 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/29 18:09:17 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	get_img(t_cub *cub, int which)
{
	if (!(cub->txt[which].img = mlx_xpm_file_to_image(cub->mlx,
	cub->txt[which].path, &cub->txt[which].width, &cub->txt[which].height)))
		ft_perror("Error: XPM file is not valid or doesn't exist!",
		ft_clean(cub, ERR));
	cub->txt[which].data = (int *)mlx_get_data_addr(cub->txt[which].img,
		&cub->txt[which].bpp, &cub->txt[which].sl, &cub->txt[which].end);
}

void	init_images(t_cub *cub)
{
	get_img(cub, NORTH);
	get_img(cub, SOUTH);
	get_img(cub, WEST);
	get_img(cub, EAST);
	get_img(cub, SPR);
}
