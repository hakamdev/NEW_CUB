/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:48:55 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 11:06:31 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	read_ceiling_color(t_cub *cub)
{
	t_str		*parts;
	t_color		clr;
	const t_str	color_values = extract_value(cub->line);

	if (cub->checker.clr_ceiling)
		ft_perror("Duplicate key (C) !", ft_clean(cub, ERR));
	parts = ft_split(color_values, ',');
	if (ft_strlen_2d(parts) != 3)
		ft_perror("3 R,G,B Values are required for (C)!", ft_clean(cub, ERR));
	if (ft_countchar(color_values, ',') > 2)
		ft_perror("Badly delimitered RGB Values!", ft_clean(cub, ERR));
	if (IS_ERR(clr.r = ft_atoi(parts[0])) || !(clr.r >= 0 && clr.r <= 255))
		ft_perror("Invalid (Red) Value for (C)!", ft_clean(cub, ERR));
	if (IS_ERR(clr.g = ft_atoi(parts[1])) || !(clr.g >= 0 && clr.g <= 255))
		ft_perror("Invalid (Green) Value for (C)!", ft_clean(cub, ERR));
	if (IS_ERR(clr.b = ft_atoi(parts[2])) || !(clr.b >= 0 && clr.b <= 255))
		ft_perror("Invalid (Blue) Value for (C)!", ft_clean(cub, ERR));
	cub->color[CIEL] = clr;
	cub->checker.clr_ceiling = true;
	ft_free(color_values);
	ft_free_2d(parts);
}

void	read_floor_color(t_cub *cub)
{
	t_str		*parts;
	t_color		clr;
	const t_str	color_values = extract_value(cub->line);

	if (cub->checker.clr_floor)
		ft_perror("Duplicate key (F) !", ft_clean(cub, ERR));
	parts = ft_split(color_values, ',');
	if (ft_strlen_2d(parts) != 3)
		ft_perror("3 R,G,B Values are required for (F)!", ft_clean(cub, ERR));
	if (ft_countchar(color_values, ',') > 2)
		ft_perror("Badly delimitered RGB Values!", ft_clean(cub, ERR));
	if (IS_ERR(clr.r = ft_atoi(parts[0])) || !(clr.r >= 0 && clr.r <= 255))
		ft_perror("Invalid (Red) Value for (F)!", ft_clean(cub, ERR));
	if (IS_ERR(clr.g = ft_atoi(parts[1])) || !(clr.g >= 0 && clr.g <= 255))
		ft_perror("Invalid (Green) Value for (F)!", ft_clean(cub, ERR));
	if (IS_ERR(clr.b = ft_atoi(parts[2])) || !(clr.b >= 0 && clr.b <= 255))
		ft_perror("Invalid (Blue) Value for (F)!", ft_clean(cub, ERR));
	cub->color[FLOOR] = clr;
	cub->checker.clr_floor = true;
	ft_free(color_values);
	ft_free_2d(parts);
}
