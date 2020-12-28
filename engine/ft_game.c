#include "../include/cubengine.h"

t_str to_lowercase(t_str str)
{
    int i;
    t_str new_str;

    i = -1;
    new_str = ft_strdup(str);
    while (new_str && new_str[++i])
        if (new_str[i] >= 'A' && new_str[i] <= 'Z')
            new_str[i] = new_str[i] + 32;
    return (new_str);
}

void check_filename(t_cub *cub, t_str fname, t_str ext, t_bool case_sens)
{
    int len;
    t_str lower_str;

    len = ft_strlen(fname);
    if (case_sens)
        lower_str = ft_strdup(&fname[len - 4]);
    else
        lower_str = to_lowercase(&fname[len - 4]);
    if (IS_SUCESS(ft_strncmp(lower_str, ext, 6)))
    {
        free(lower_str);
        return;
    }
    free(lower_str);
    if (IS_SUCESS(ft_strncmp(ext, ".cub", 4)))
        ft_perror("Config file should be of type (.cub) !",
                  ft_clean(cub, ERROR));
    else
        ft_perror("Texture/Sprite file should be of type (.xpm) !",
                  ft_clean(cub, ERROR));
}

void check_arguments(t_cub *cub, int ac, t_str *av)
{
    if (ac < 2)
        ft_perror("Config (.cub) file is required for the game to run!",
                  ft_clean(cub, ERROR));
    else if (ac > 3)
        ft_perror("No more than 2 Arguments are allowed!",
                  ft_clean(cub, ERROR));
    check_filename(cub, av[1], ".cub", true);
    if (ac == 3)
	{
        if (!IS_SUCESS(ft_strncmp(av[2], "--save", 7)))
        	ft_perror("Second Argument is not corrent!", ft_clean(cub, ERROR));
		else
			cub->screenshot = true;
	}
}

int main(int ac, t_str *av)
{
    t_cub cub;

	init_cub(&cub);
    check_arguments(&cub, ac, av);
    read_file(&cub, av[1]);
}