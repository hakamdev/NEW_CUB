/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:34:36 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/03 19:20:12 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

int		round_four(int width)
{
	return (width % 4 == 0 ? width : width - width % 4 + 4);
}

void	fill_colors(t_cub *cub, char **bmp_data, int bmp_size, int pad_width)
{
	int		index;
	int		x;
	int		y;
	t_color	color;

	index = -1;
	while (++index < bmp_size)
		bmp_data[0][index] = (char)0;
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			color = color_hex_to_rgb(cub->cnvs.data[y * WIN_WIDTH + x]);
			index = (WIN_HEIGHT - 1 - y) * pad_width + x * 3;
			bmp_data[0][index++] = color.b;
			bmp_data[0][index++] = color.g;
			bmp_data[0][index] = color.r;
		}
		
	}
	
}

void	save(t_cub *cub)
{
	const char	tag[] = {'B', 'M'};
	int			header[] = { 0, 0, 0x36, 0x28, WIN_WIDTH, WIN_HEIGHT,
				0x180001, 0, 0, 0x002e23, 0x002e23, 0, 0 };
	const int	fd = open("image.bmp",
				O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	const int	padded_width = round_four(WIN_WIDTH * 3);
	const int	bitmap_size = WIN_HEIGHT * padded_width * 3;
	char		*bmp_data;
	
	event_game_loop(cub);
	if (!(bmp_data = (char *)malloc(bitmap_size * sizeof(char))))
		ft_perror("Failed to allocate memory for BMP!", ft_clean(cub, ERR));
	fill_colors(cub, &bmp_data, bitmap_size, padded_width);
	header[0] = sizeof(tag) + sizeof(header) + bitmap_size;
	write(fd, tag, sizeof(tag));
	write(fd, header, sizeof(header));
	write(fd, bmp_data, bitmap_size * sizeof(char));
	close(fd);
	ft_free(bmp_data);
	exit(ft_clean(cub, SUCCESS));
}