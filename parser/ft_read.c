/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:52:37 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:33:03 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	handle_keys(t_cub *cub)
{
	if (ft_strncmp(cub->parts[0], "R", 2) == SUCCESS)
		read_resolution(cub);
	else if (ft_strncmp(cub->parts[0], "NO", 3) == SUCCESS)
		read_north_texture(cub);
	else if (ft_strncmp(cub->parts[0], "SO", 3) == SUCCESS)
		read_south_texture(cub);
	else if (ft_strncmp(cub->parts[0], "WE", 3) == SUCCESS)
		read_west_texture(cub);
	else if (ft_strncmp(cub->parts[0], "EA", 3) == SUCCESS)
		read_east_texture(cub);
	else if (ft_strncmp(cub->parts[0], "S", 2) == SUCCESS)
		read_sprite(cub);
	else if (ft_strncmp(cub->parts[0], "F", 2) == SUCCESS)
		read_floor_color(cub);
	else if (ft_strncmp(cub->parts[0], "C", 2) == SUCCESS)
		read_ceiling_color(cub);
	else if (ft_strnchar("012NEWS ", *cub->line) && !is_read_complete(cub))
		ft_perror("Missing/Missplaced keys!", ft_clean(cub, ERR));
	else if (ft_strnchar("012NEWS ", *cub->line) && is_read_complete(cub))
		read_map(cub);
	else
		ft_perror("Unreconizable keys or Split map!", ft_clean(cub, ERR));
}

void	process_line(t_cub *cub)
{
	if (cub->line && ft_strlen(cub->line) == 0 && !cub->checker.is_map)
		return (ft_free(&cub->line));
	cub->parts = ft_split(cub->line, ' ');
	handle_keys(cub);
	ft_free(&cub->line);
	ft_free_2d(&cub->parts);
}

void	read_file(t_cub *cub, t_str filename)
{
	int		fd;
	int		read_num;
	t_bool	is_first_loop;

	read_num = 0;
	is_first_loop = true;
	init_read_check(cub);
	if ((fd = open(filename, O_RDONLY)) == ERR)
		ft_perror("Failed to open file for reading.\nIs the filename correct?",
			ft_clean(cub, ERR));
	while ((read_num = get_next_line(fd, &cub->line)) > 0)
	{
		is_first_loop = false;
		process_line(cub);
	}
	if (is_first_loop == true && read_num == 0 && !*cub->line)
		ft_perror("It appears to be an Empty file!", ft_clean(cub, ERR));
	if (read_num == ERR)
		ft_perror("Failed to read from file!", ft_clean(cub, ERR));
	process_line(cub);
	check_all(cub);
	if (close(fd) == ERR)
		ft_perror("Failed to close file after read!", ft_clean(cub, ERR));
}
