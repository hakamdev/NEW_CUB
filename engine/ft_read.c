#include "../include/cubengine.h"

int		init_read_check(t_cub *cub)
{
    cub->checker.resolution = false;
    cub->checker.txt_north = false;
    cub->checker.txt_south = false;
    cub->checker.txt_west = false;
    cub->checker.txt_east = false;
    cub->checker.txt_sprite = false;
    cub->checker.clr_ceiling = false;
    cub->checker.clr_floor = false;
}

t_bool	is_read_complete(t_cub *cub)
{
    return (cub->checker.resolution == true && cub->checker.txt_north == true &&
            cub->checker.txt_south == true && cub->checker.txt_west == true &&
            cub->checker.txt_east == true && cub->checker.txt_sprite == true &&
            cub->checker.clr_ceiling == true && cub->checker.clr_floor == true);
}

void	read_resolution(t_cub *cub, t_str *parts)
{
	if (cub->checker.resolution)
		ft_perror("Error: Duplicate Key (R)!", ft_clean(cub, ERROR));
	if (ft_strlen_2d(parts) > 3)
		ft_perror("Error: Additional Agruments in Resolution!", ft_clean(cub, ERROR));
	if (IS_ERROR(cub->cnvs.width = ft_atoi(parts[1])))
		ft_perror("Error: Invalid Value for Resolution (Width)!", ft_clean(cub, ERROR));
	if (IS_ERROR(cub->cnvs.height = ft_atoi(parts[2])))
		ft_perror("Error: Invalid Value for Resolution (Height)!", ft_clean(cub, ERROR));
}

void	handle_keys(t_cub *cub, t_str line, t_str *parts) {
	if (IS_SUCESS(ft_strncmp(parts[0], "R", ft_strlen(parts[0]))))
		read_resolution(cub, parts);
	else if (IS_SUCESS(ft_strncmp(parts[0], "NO", ft_strlen(parts[0]))));

	else if (IS_SUCESS(ft_strncmp(parts[0], "SO", ft_strlen(parts[0]))));

	else if (IS_SUCESS(ft_strncmp(parts[0], "WE", ft_strlen(parts[0]))));

	else if (IS_SUCESS(ft_strncmp(parts[0], "EA", ft_strlen(parts[0]))));

	else if (IS_SUCESS(ft_strncmp(parts[0], "S", ft_strlen(parts[0]))));

	else if (IS_SUCESS(ft_strncmp(parts[0], "F", ft_strlen(parts[0]))));

	else if (IS_SUCESS(ft_strncmp(parts[0], "C", ft_strlen(parts[0]))));

	else
		ft_perror("Error: Unrecognizable Elements!", ft_clean(cub, ERROR));
}

void	handle_map(t_cub *cub, t_str line)
{

}

int		process_line(t_cub *cub, t_str line)
{
	if (!is_read_complete(cub))
		handle_keys(cub, line, ft_split(line, ' '));
	else
		handle_map(cub, line);
	return (0);
}







