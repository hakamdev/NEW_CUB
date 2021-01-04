/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:07:26 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:09:33 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

t_bool	is_read_complete(t_cub *cub)
{
	return (cub->checker.resolution && cub->checker.txt_north &&
			cub->checker.txt_south && cub->checker.txt_west &&
			cub->checker.txt_east && cub->checker.txt_sprite &&
			cub->checker.clr_ceiling && cub->checker.clr_floor);
}

t_str	extract_value(t_str line)
{
	int start;
	int end;

	start = 0;
	end = ft_strlen(line) - 1;
	while (line[start] && line[start] == ' ')
		start++;
	while (line[start] && line[start] != ' ')
		start++;
	while (line[start] && line[start] == ' ')
		start++;
	while (end > 0 && line[end] == ' ')
		end--;
	line[end + 1] = '\0';
	return (ft_strdup(&line[start]));
}
