#include "../include/cubengine.h"

void init_read_check(t_cub *cub)
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

t_bool is_read_complete(t_cub *cub)
{
	return (cub->checker.resolution && cub->checker.txt_north &&
			cub->checker.txt_south && cub->checker.txt_west &&
			cub->checker.txt_east && cub->checker.txt_sprite &&
			cub->checker.clr_ceiling && cub->checker.clr_floor);
}

void read_resolution(t_cub *cub, t_str *parts)
{
	if (cub->checker.resolution)
		ft_perror("Error: Duplicate Key (R)!", ft_clean(cub, ERROR));
	if (ft_strlen_2d(parts) < 3)
		ft_perror("Error: Missing Agruments for Resolution!", ft_clean(cub, ERROR));
	if (ft_strlen_2d(parts) > 3)
		ft_perror("Error: Additional Agruments for Resolution!", ft_clean(cub, ERROR));
	if (IS_ERROR(cub->cnvs.width = ft_atoi(parts[1])) || cub->cnvs.width == 0)
		ft_perror("Error: Invalid Value for Resolution (Width)!", ft_clean(cub, ERROR));

	if (IS_ERROR(cub->cnvs.height = ft_atoi(parts[2])) || cub->cnvs.height == 0)
		ft_perror("Error: Invalid Value for Resolution (Height)!", ft_clean(cub, ERROR));
	cub->checker.resolution = true;
}

t_str extract_texture_path(t_str line)
{
	int start;
	int end;

	start = 0;
	end = ft_strlen(line) - 1;
	while (line[start] != ' ')
		start++;
	while (line[start] == ' ')
		start++;
	while (end > 0 && line[end] == ' ')
		end--;
	line[end + 1] = '\0';
	return (ft_strdup(&line[start]));
}

t_str to_lowercase(t_str str)
{
	int i;
	t_str new_str;

	i = 0;
	new_str = ft_strdup(str);
	while (new_str && new_str[i])
		if (new_str[i] >= 'A' && new_str[i] <= 'Z')
			new_str[i] = new_str[i] + 32;
	return (new_str);
}

void read_north_texture(t_cub *cub, t_str line, t_str which)
{
	t_str path;

	if (cub->checker.txt_north)
		ft_perror("Error: Duplicate key (NO) !", ft_clean(cub, ERROR));
	path = extract_texture_path(line);
	check_filename(cub, path, ".xpm");
}

void handle_keys(t_cub *cub, t_str line, t_str *parts)
{
	if (IS_SUCESS(ft_strncmp(parts[0], "R", ft_strlen(parts[0]))))
		read_resolution(cub, parts);
	else if (IS_SUCESS(ft_strncmp(parts[0], "NO", ft_strlen(parts[0]))))
		;

	else if (IS_SUCESS(ft_strncmp(parts[0], "SO", ft_strlen(parts[0]))))
		;

	else if (IS_SUCESS(ft_strncmp(parts[0], "WE", ft_strlen(parts[0]))))
		;

	else if (IS_SUCESS(ft_strncmp(parts[0], "EA", ft_strlen(parts[0]))))
		;

	else if (IS_SUCESS(ft_strncmp(parts[0], "S", ft_strlen(parts[0]))))
		;

	else if (IS_SUCESS(ft_strncmp(parts[0], "F", ft_strlen(parts[0]))))
		;

	else if (IS_SUCESS(ft_strncmp(parts[0], "C", ft_strlen(parts[0]))))
		;

	else if (!ft_strnchar("012NEWS ", line[0]))
		ft_perror(line, ft_clean(cub, ERROR));
	free_2d(parts);
}

void handle_map(t_cub *cub, t_str line)
{
}

int process_line(t_cub *cub, t_str line)
{
	if (!is_read_complete(cub))
		handle_keys(cub, line, ft_split(line, ' '));
	else
		handle_map(cub, line);
	return (0);
}

int read_file(t_cub *cub, t_str filename)
{
	int fd;
	int read_num;
	t_str line;
	t_bool is_first_loop;

	read_num = 0;
	is_first_loop = true;
	init_read_check(cub);
	if (IS_ERROR(fd = open(filename, O_RDONLY)))
		ft_perror("Error: Failed to open file for reading.\nIs the filename correct?",
				  ft_clean(cub, ERROR));
	while ((read_num = get_next_line(fd, &line)) > 0)
	{
		if (is_first_loop && read_num == 0)
			ft_perror("Error: It appears to be an Empty file!", ft_clean(cub, ERROR));
		is_first_loop = false;
		process_line(cub, line);
	}
	if (IS_ERROR(read_num))
		ft_perror("Error: Failed to read from file!", ft_clean(cub, ERROR));
	process_line(cub, line);
	if (IS_ERROR(close(fd)))
		ft_perror("Error: Failed to close file after read!", ft_clean(cub, ERROR));
	return (SUCCESS);
}
