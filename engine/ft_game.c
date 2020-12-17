#include "../include/cubengine.h"

void check_filename(t_cub *cub, t_str filename, t_str extension)
{
    int len;

    len = ft_strlen(filename);
    if (IS_SUCESS(ft_strncmp(&filename[len - 4], extension, 6)))
        return;
    ft_perror("Error: Config file should be of type (.cub) !", ft_clean(cub, ERROR));
}

void check_second_arg(t_cub *cub, t_str arg)
{
    if (IS_SUCESS(ft_strncmp(arg, "--save", 7)))
        ft_perror("Error: Second Argument is not corrent!",
                  ft_clean(cub, ERROR));
}

void check_arguments(t_cub *cub, int ac, t_str *av)
{
    if (ac < 2)
        ft_perror("Error: Config (.cub) file is required for the game to run!",
                  ft_clean(cub, ERROR));
    if (ac > 3)
        ft_perror("Error: No more than 2 Arguments are allowed!",
                  ft_clean(cub, ERROR));
    check_filename(cub, av[1], ".cub");
    if (ac == 3)
        check_second_arg(cub, av[2]);
}

int main(int ac, t_str *av)
{
    t_cub cub;
    check_arguments(&cub, ac, av);
    read_file(&cub, av[1]);
}