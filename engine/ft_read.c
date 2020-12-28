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
	cub->checker.is_map = false;
}

t_bool is_read_complete(t_cub *cub)
{
	return (cub->checker.resolution && cub->checker.txt_north &&
			cub->checker.txt_south && cub->checker.txt_west &&
			cub->checker.txt_east && cub->checker.txt_sprite &&
			cub->checker.clr_ceiling && cub->checker.clr_floor);
}

t_str extract_value(t_str line)
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

int countchar(const t_str str, char c)
{
	int i;
	int ccount;

	if (!str)
		return (0);
	i = -1;
	ccount = 0;
	while (str[++i])
		if (str[i] == c)
			ccount++;
	return (ccount);
}

void read_resolution(t_cub *cub)
{
	if (cub->checker.resolution)
		ft_perror("Duplicate Key (R)!", ft_clean(cub, ERROR));
	if (ft_strlen_2d(cub->parts) < 3)
		ft_perror("Missing Agruments for Resolution!", ft_clean(cub, ERROR));
	if (ft_strlen_2d(cub->parts) > 3)
		ft_perror("Additional Agruments for Resolution!", ft_clean(cub, ERROR));
	if (IS_ERROR(cub->cnvs.width = ft_atoi(cub->parts[1])) || cub->cnvs.width <= 0)
		ft_perror("Invalid Value for Resolution!", ft_clean(cub, ERROR));
	if (IS_ERROR(cub->cnvs.height = ft_atoi(cub->parts[2])) || cub->cnvs.height <= 0)
		ft_perror("Invalid Value for Resolution!", ft_clean(cub, ERROR));
	cub->cnvs.width = cub->cnvs.width > MAX_WIDTH ? MAX_WIDTH : cub->cnvs.width;
	cub->cnvs.height = cub->cnvs.height > MAX_HEIGHT ? MAX_HEIGHT : cub->cnvs.height;
	cub->checker.resolution = true;
}

void read_north_texture(t_cub *cub)
{
	t_str path;
	int fd;

	if (cub->checker.txt_north)
		ft_perror("Duplicate key (NO) !", ft_clean(cub, ERROR));
	if (ft_strlen_2d(cub->parts) < 2)
		ft_perror("No Path provided for(NO) !", ft_clean(cub, ERROR));
	path = extract_value(cub->line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[NORTH].path = path;
	cub->checker.txt_north = true;
	if (IS_ERROR(fd = open(path, O_RDONLY)))
		ft_perror("The path to (NO) texture is not valid!", ft_clean(cub, ERROR));
	close(fd);
}

void read_south_texture(t_cub *cub)
{
	t_str path;
	int fd;

	if (cub->checker.txt_south)
		ft_perror("Duplicate key (SO) !", ft_clean(cub, ERROR));
	if (ft_strlen_2d(cub->parts) < 2)
		ft_perror("No Path provided for(SO) !", ft_clean(cub, ERROR));
	path = extract_value(cub->line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[SOUTH].path = path;
	cub->checker.txt_south = true;
	if (IS_ERROR(fd = open(path, O_RDONLY)))
		ft_perror("The path to (SO) texture is not valid!", ft_clean(cub, ERROR));
	close(fd);
}

void read_west_texture(t_cub *cub)
{
	t_str path;
	int fd;

	if (cub->checker.txt_west)
		ft_perror("Duplicate key (WE) !", ft_clean(cub, ERROR));
	if (ft_strlen_2d(cub->parts) < 2)
		ft_perror("No Path provided for(WE) !", ft_clean(cub, ERROR));
	path = extract_value(cub->line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[WEST].path = path;
	cub->checker.txt_west = true;
	if (IS_ERROR(fd = open(path, O_RDONLY)))
		ft_perror("The path to (WE) texture is not valid!", ft_clean(cub, ERROR));
	close(fd);
}

void read_east_texture(t_cub *cub)
{
	t_str path;
	int fd;

	if (cub->checker.txt_east)
		ft_perror("Duplicate key (EA) !", ft_clean(cub, ERROR));
	if (ft_strlen_2d(cub->parts) < 2)
		ft_perror("No Path provided for(EA) !", ft_clean(cub, ERROR));
	path = extract_value(cub->line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[EAST].path = path;
	cub->checker.txt_east = true;
	if (IS_ERROR(fd = open(path, O_RDONLY)))
		ft_perror("The path to (EA) texture is not valid!", ft_clean(cub, ERROR));
	close(fd);
}

void read_sprite(t_cub *cub)
{
	t_str path;
	int fd;

	if (cub->checker.txt_sprite)
		ft_perror("Duplicate key (S) !", ft_clean(cub, ERROR));
	if (ft_strlen_2d(cub->parts) < 2)
		ft_perror("No Path provided for(S) !", ft_clean(cub, ERROR));
	path = extract_value(cub->line);
	check_filename(cub, path, ".xpm", false);
	cub->txt[SPR].path = path;
	cub->checker.txt_sprite = true;
	if (IS_ERROR(fd = open(path, O_RDONLY)))
		ft_perror("The path to (S) sprite is not valid!", ft_clean(cub, ERROR));
	close(fd);
}

void read_ceiling_color(t_cub *cub)
{
	t_str *parts;
	t_color color;
	const t_str color_values = extract_value(cub->line);

	if (cub->checker.clr_ceiling)
		ft_perror("Duplicate key (C) !", ft_clean(cub, ERROR));
	parts = ft_split(color_values, ',');
	if (ft_strlen_2d(parts) != 3)
		ft_perror("3 R,G,B Values are required for (C)!", ft_clean(cub, ERROR));
	if (countchar(color_values, ',') > 2)
		ft_perror("Badly delimitered RGB Values!", ft_clean(cub, ERROR));
	if (IS_ERROR(color.r = ft_atoi(parts[0])) || !(color.r >= 0 && color.r <= 255))
		ft_perror("Invalid (Red) Value for (C)!", ft_clean(cub, ERROR));
	if (IS_ERROR(color.g = ft_atoi(parts[1])) || !(color.g >= 0 && color.g <= 255))
		ft_perror("Invalid (Green) Value for (C)!", ft_clean(cub, ERROR));
	if (IS_ERROR(color.b = ft_atoi(parts[2])) || !(color.b >= 0 && color.b <= 255))
		ft_perror("Invalid (Blue) Value for (C)!", ft_clean(cub, ERROR));
	cub->color[CIEL] = color;
	cub->checker.clr_ceiling = true;
	free_2d(parts);
}

void read_floor_color(t_cub *cub)
{
	t_str *parts;
	t_color color;
	const t_str color_values = extract_value(cub->line);

	if (cub->checker.clr_floor)
		ft_perror("Duplicate key (F) !", ft_clean(cub, ERROR));
	parts = ft_split(color_values, ',');
	if (ft_strlen_2d(parts) != 3)
		ft_perror("3 R,G,B Values are required for (F)!", ft_clean(cub, ERROR));
	if (countchar(color_values, ',') > 2)
		ft_perror("Badly delimitered RGB Values!", ft_clean(cub, ERROR));
	if (IS_ERROR(color.r = ft_atoi(parts[0])) || !(color.r >= 0 && color.r <= 255))
		ft_perror("Invalid (Red) Value for (F)!", ft_clean(cub, ERROR));
	if (IS_ERROR(color.g = ft_atoi(parts[1])) || !(color.g >= 0 && color.g <= 255))
		ft_perror("Invalid (Green) Value for (F)!", ft_clean(cub, ERROR));
	if (IS_ERROR(color.b = ft_atoi(parts[2])) || !(color.b >= 0 && color.b <= 255))
		ft_perror("Invalid (Blue) Value for (F)!", ft_clean(cub, ERROR));
	cub->color[FLOOR] = color;
	cub->checker.clr_floor = true;
	free_2d(parts);
}

void read_map(t_cub *cub) {
	int		i;
	t_map	*tmap;

	cub->checker.is_map = true;
	if (cub->map == NULL)
	{
		if(!(cub->map = malloc(1 * sizeof(t_map))))
			ft_perror("Error: Failed to allocate memory!", ft_clean(cub, ERROR));
		cub->map[0].row = ft_strdup(cub->line);
		cub->map[0].columns = ft_strlen(cub->line);
		cub->rows_nb = 1;
		return ;
	}
	i = -1;
	tmap = cub->map;
	if(!(cub->map = malloc(++(cub->rows_nb) * sizeof(t_map))))
		ft_perror("Error: Failed to allocate memory!", ft_clean(cub, ERROR));
	while (++i < cub->rows_nb - 1)
		cub->map[i] = tmap[i];
	cub->map[i].row = ft_strdup(cub->line);
	cub->map[i].columns = ft_strlen(cub->line);
	free(tmap);
}

void handle_keys(t_cub *cub)
{
	if (IS_SUCESS(ft_strncmp(cub->parts[0], "R", 2)))
		read_resolution(cub);
	else if (IS_SUCESS(ft_strncmp(cub->parts[0], "NO", 3)))
		read_north_texture(cub);
	else if (IS_SUCESS(ft_strncmp(cub->parts[0], "SO", 3)))
		read_south_texture(cub);
	else if (IS_SUCESS(ft_strncmp(cub->parts[0], "WE", 3)))
		read_west_texture(cub);
	else if (IS_SUCESS(ft_strncmp(cub->parts[0], "EA", 3)))
		read_east_texture(cub);
	else if (IS_SUCESS(ft_strncmp(cub->parts[0], "S", 2)))
		read_sprite(cub);
	else if (IS_SUCESS(ft_strncmp(cub->parts[0], "F", 2)))
		read_floor_color(cub);
	else if (IS_SUCESS(ft_strncmp(cub->parts[0], "C", 2)))
		read_ceiling_color(cub);
	else if (ft_strnchar("012NEWS ", *cub->line) && !is_read_complete(cub))
		ft_perror("Missing/Missplaced keys!", ft_clean(cub, ERROR));
	else if (ft_strnchar("012NEWS ", *cub->line) && is_read_complete(cub))
		read_map(cub);
	else
		ft_perror("Unreconizable keys or Split map!", ft_clean(cub, ERROR));
}

void process_line(t_cub *cub)
{
	if (cub->line && ft_strlen(cub->line) == 0 && !cub->checker.is_map)
		return (ft_free(cub->line));
	cub->parts = ft_split(cub->line, ' ');
	handle_keys(cub);
	ft_free(cub->line);
	free_2d(cub->parts);
}

void read_file(t_cub *cub, t_str filename)
{
	int fd;
	int read_num;
	t_bool is_first_loop;

	read_num = 0;
	is_first_loop = true;
	init_read_check(cub);
	if (IS_ERROR(fd = open(filename, O_RDONLY)))
		ft_perror("Failed to open file for reading.\nIs the filename correct?",
				  ft_clean(cub, ERROR));
	int x = 1;
	while ((read_num = get_next_line(fd, &cub->line)) > 0)
	{
		is_first_loop = false;
		process_line(cub);
	}
	if (is_first_loop == true && read_num == 0 && !*cub->line)
		ft_perror("It appears to be an Empty file!", ft_clean(cub, ERROR));
	if (IS_ERROR(read_num))
		ft_perror("Failed to read from file!", ft_clean(cub, ERROR));
	process_line(cub);
	check_all(cub);
	if (IS_ERROR(close(fd)))
		ft_perror("Failed to close file after read!", ft_clean(cub, ERROR));


	///////////////////////
	write(1, "\033[0;32m", 8);
	printf("RES: \n");
	printf("WIDTH  = |%04d|\n", cub->cnvs.width);
	printf("HEIGHT = |%04d|\n\n", cub->cnvs.height);
	write(1, "\033[0;33m", 8);
	printf("TEXTURES: \n");
	printf("NO = |%30s|\n", cub->txt[NORTH].path);
	printf("SO = |%30s|\n", cub->txt[SOUTH].path);
	printf("WE = |%30s|\n", cub->txt[WEST].path);
	printf("EA = |%30s|\n", cub->txt[EAST].path);
	printf("S  = |%30s|\n\n", cub->txt[SPR].path);
	write(1, "\033[0;34m", 8);
	printf("COLORS: \n");
	printf("F = |R:%03d|G:%03d|B:%03d|\n", cub->color[FLOOR].r, cub->color[FLOOR].g, cub->color[FLOOR].b);
	printf("C = |R:%03d|G:%03d|B:%03d|\n\n", cub->color[CIEL].r, cub->color[CIEL].g, cub->color[CIEL].b);
	write(1, "\033[0;35m", 8);
	printf("MAP: \n");
	for (int i = 0; i < cub->rows_nb; i++)
		printf("%02d |%s|\n", i, cub->map[i].row);
	///////////////////////
}
