/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:34:36 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:50:14 by ehakam           ###   ########.fr       */
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
	while (++y < cub->cnvs.height)
	{
		x = -1;
		while (++x < cub->cnvs.width)
		{
			color = color_hex_to_rgb(cub->cnvs.data[y * cub->cnvs.width + x]);
			index = (cub->cnvs.height - 1 - y) * pad_width + x * 3;
			bmp_data[0][index++] = color.b;
			bmp_data[0][index++] = color.g;
			bmp_data[0][index] = color.r;
		}
	}
}

int		*fill_header(t_cub *cub)
{
	int		*header;

	if (!(header = (int *)malloc(13 * sizeof(int))))
		ft_perror("Failed to alloc memory for BMP Header!", ft_clean(cub, ERR));
	header[0] = 0;
	header[1] = 0;
	header[2] = 0x36;
	header[3] = 0x28;
	header[4] = cub->cnvs.width;
	header[5] = cub->cnvs.height;
	header[6] = 0x180001;
	header[7] = 0;
	header[8] = 0;
	header[9] = 0x002e23;
	header[10] = 0x002e23;
	header[11] = 0;
	header[12] = 0;
	return (header);
}

void	save(t_cub *cub)
{
	char		*bmp_data;
	int			*header;
	int			fd;
	int			bitmap_size;
	const char	tag[] = "BM";

	bitmap_size = cub->cnvs.height * round_four(cub->cnvs.width * 3) * 3;
	event_game_loop(cub);
	header = fill_header(cub);
	if (!(bmp_data = (char *)malloc(bitmap_size * sizeof(char))))
		ft_perror("Failed to allocate memory for BMP!", ft_clean(cub, ERR));
	fill_colors(cub, &bmp_data, bitmap_size, round_four(cub->cnvs.width * 3));
	header[0] = sizeof(tag) + sizeof(header) + bitmap_size;
	if (!(fd = open("ss.bmp", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)))
		ft_perror("Failed to access BMP file!", ft_clean(cub, ERR));
	write(fd, tag, 2 * sizeof(char));
	write(fd, header, 13 * sizeof(int));
	write(fd, bmp_data, bitmap_size * sizeof(char));
	close(fd);
	ft_free(&bmp_data);
	free(header);
	exit(ft_clean(cub, SUCCESS));
}
