/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:49:32 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:37:04 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	read_resolution(t_cub *cub)
{
	if (cub->checker.resolution)
		ft_perror("Duplicate Key (R)!", ft_clean(cub, ERR));
	if (ft_strlen_2d(cub->parts) < 3)
		ft_perror("Missing Agruments for Resolution!", ft_clean(cub, ERR));
	if (ft_strlen_2d(cub->parts) > 3)
		ft_perror("Additional Agruments for Resolution!", ft_clean(cub, ERR));
	if ((cub->cnvs.width = ft_atoi(cub->parts[1])) == ERR
		|| cub->cnvs.width <= 0)
		ft_perror("Invalid Value for Resolution!", ft_clean(cub, ERR));
	if ((cub->cnvs.height = ft_atoi(cub->parts[2])) == ERR
		|| cub->cnvs.height <= 0)
		ft_perror("Invalid Value for Resolution!", ft_clean(cub, ERR));
	cub->cnvs.width = cub->cnvs.width > MAX_WIDTH ? MAX_WIDTH : cub->cnvs.width;
	cub->cnvs.height = cub->cnvs.height > MAX_HEIGHT ? MAX_HEIGHT
		: cub->cnvs.height;
	cub->checker.resolution = true;
}
