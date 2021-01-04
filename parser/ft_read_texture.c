/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:44:29 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:38:16 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	read_north_texture(t_cub *cub)
{
	t_str	path;
	int		fd;

	if (cub->checker.txt_north)
		ft_perror("Duplicate key (NO) !", ft_clean(cub, ERR));
	if (ft_strlen_2d(cub->parts) < 2)
		ft_perror("No Path provided for(NO) !", ft_clean(cub, ERR));
	path = extract_value(cub->line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[NORTH].path = path;
	cub->checker.txt_north = true;
	if ((fd = open(path, O_RDONLY)) == ERR)
		ft_perror("The path to (NO) texture is not valid!", ft_clean(cub, ERR));
	close(fd);
}

void	read_south_texture(t_cub *cub)
{
	t_str	path;
	int		fd;

	if (cub->checker.txt_south)
		ft_perror("Duplicate key (SO) !", ft_clean(cub, ERR));
	if (ft_strlen_2d(cub->parts) < 2)
		ft_perror("No Path provided for(SO) !", ft_clean(cub, ERR));
	path = extract_value(cub->line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[SOUTH].path = path;
	cub->checker.txt_south = true;
	if ((fd = open(path, O_RDONLY)) == ERR)
		ft_perror("The path to (SO) texture is not valid!", ft_clean(cub, ERR));
	close(fd);
}

void	read_west_texture(t_cub *cub)
{
	t_str	path;
	int		fd;

	if (cub->checker.txt_west)
		ft_perror("Duplicate key (WE) !", ft_clean(cub, ERR));
	if (ft_strlen_2d(cub->parts) < 2)
		ft_perror("No Path provided for(WE) !", ft_clean(cub, ERR));
	path = extract_value(cub->line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[WEST].path = path;
	cub->checker.txt_west = true;
	if ((fd = open(path, O_RDONLY)) == ERR)
		ft_perror("The path to (WE) texture is not valid!", ft_clean(cub, ERR));
	close(fd);
}

void	read_east_texture(t_cub *cub)
{
	t_str	path;
	int		fd;

	if (cub->checker.txt_east)
		ft_perror("Duplicate key (EA) !", ft_clean(cub, ERR));
	if (ft_strlen_2d(cub->parts) < 2)
		ft_perror("No Path provided for(EA) !", ft_clean(cub, ERR));
	path = extract_value(cub->line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[EAST].path = path;
	cub->checker.txt_east = true;
	if ((fd = open(path, O_RDONLY)) == ERR)
		ft_perror("The path to (EA) texture is not valid!", ft_clean(cub, ERR));
	close(fd);
}

void	read_sprite(t_cub *cub)
{
	t_str	path;
	int		fd;

	if (cub->checker.txt_sprite)
		ft_perror("Duplicate key (S) !", ft_clean(cub, ERR));
	if (ft_strlen_2d(cub->parts) < 2)
		ft_perror("No Path provided for(S) !", ft_clean(cub, ERR));
	path = extract_value(cub->line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[SPR].path = path;
	cub->checker.txt_sprite = true;
	if ((fd = open(path, O_RDONLY)) == ERR)
		ft_perror("The path to (S) sprite is not valid!", ft_clean(cub, ERR));
	close(fd);
}
