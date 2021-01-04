/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:05:59 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:04:07 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

float	ft_distance(t_cub *cub, float x, float y)
{
	return (sqrtf(powf(x - cub->cam.x, 2) + powf(y - cub->cam.y, 2)));
}
