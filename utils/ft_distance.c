/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:05:59 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/30 17:06:30 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

float	ft_distance(t_cub *cub, float x, float y)
{
	return (sqrtf(POW(x - cub->cam.x) + POW(y - cub->cam.y)));
}
