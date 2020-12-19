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

void read_north_texture(t_cub *cub, t_str line)
{
	t_str path;
	int fd;

	if (cub->checker.txt_north)
		ft_perror("Error: Duplicate key (NO) !", ft_clean(cub, ERROR));
	path = extract_texture_path(line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[NORTH].path = path;
	cub->checker.txt_north = true;
	if (IS_ERROR(fd = open(path, O_RDONLY)))
		ft_perror("Error: The path to (NO) texture is not valid!", ft_clean(cub, ERROR));
	close(fd);
}

void read_south_texture(t_cub *cub, t_str line)
{
	t_str path;
	int fd;

	if (cub->checker.txt_south)
		ft_perror("Error: Duplicate key (SO) !", ft_clean(cub, ERROR));
	path = extract_texture_path(line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[SOUTH].path = path;
	cub->checker.txt_south = true;
	if (IS_ERROR(fd = open(path, O_RDONLY)))
		ft_perror("Error: The path to (SO) texture is not valid!", ft_clean(cub, ERROR));
	close(fd);
}

void read_west_texture(t_cub *cub, t_str line)
{
	t_str path;
	int fd;

	if (cub->checker.txt_west)
		ft_perror("Error: Duplicate key (WE) !", ft_clean(cub, ERROR));
	path = extract_texture_path(line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[WEST].path = path;
	cub->checker.txt_west = true;
	if (IS_ERROR(fd = open(path, O_RDONLY)))
		ft_perror("Error: The path to (WE) texture is not valid!", ft_clean(cub, ERROR));
	close(fd);
}

void read_east_texture(t_cub *cub, t_str line)
{
	t_str path;
	int fd;

	if (cub->checker.txt_east)
		ft_perror("Error: Duplicate key (EA) !", ft_clean(cub, ERROR));
	path = extract_texture_path(line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[EAST].path = path;
	cub->checker.txt_east = true;
	if (IS_ERROR(fd = open(path, O_RDONLY)))
		ft_perror("Error: The path to (EA) texture is not valid!", ft_clean(cub, ERROR));
	close(fd);
}

void read_sprite(t_cub *cub, t_str line)
{
	t_str path;
	int fd;

	if (cub->checker.txt_sprite)
		ft_perror("Error: Duplicate key (S) !", ft_clean(cub, ERROR));
	path = extract_texture_path(line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[SPR].path = path;
	cub->checker.txt_sprite = true;
	if (IS_ERROR(fd = open(path, O_RDONLY)))
		ft_perror("Error: The path to (S) sprite is not valid!", ft_clean(cub, ERROR));
	close(fd);
}

void handle_keys(t_cub *cub, t_str line, t_str *parts)
{
	if (IS_SUCESS(ft_strncmp(parts[0], "R", 2)))
		read_resolution(cub, parts);
	else if (IS_SUCESS(ft_strncmp(parts[0], "NO", 3)))
		read_north_texture(cub, line);
	else if (IS_SUCESS(ft_strncmp(parts[0], "SO", 3)))
		read_south_texture(cub, line);
	else if (IS_SUCESS(ft_strncmp(parts[0], "WE", 3)))
		read_west_texture(cub, line);
	else if (IS_SUCESS(ft_strncmp(parts[0], "EA", 3)))
		read_east_texture(cub, line);
	else if (IS_SUCESS(ft_strncmp(parts[0], "S", 2)))
		read_sprite(cub, line);
	else if (IS_SUCESS(ft_strncmp(parts[0], "F", 2)))
		;
	else if (IS_SUCESS(ft_strncmp(parts[0], "C", 2)))
		;
	else
		ft_perror("Error: Unreconizable keys! ", ft_clean(cub, ERROR));
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
	///////////////////////
	printf("TEXTURE: \n");
	printf("NO = |%s|\n", cub->txt[NORTH].path);
	printf("SO = |%s|\n", cub->txt[SOUTH].path);
	printf("WE = |%s|\n", cub->txt[WEST].path);
	printf("EA = |%s|\n", cub->txt[EAST].path);
	///////////////////////

	return (SUCCESS);
}
