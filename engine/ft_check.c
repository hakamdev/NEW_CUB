/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:51:36 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/28 18:53:35 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	check_filename(t_cub *cub, t_str fname, t_str ext, t_bool case_sens)
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

void	check_arguments(t_cub *cub, int ac, t_str *av)
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

void	check_map_element(t_cub *cub, int i, int j)
{
	int		m;
	int		n;

	n = -2;
	while (++n <= 1)
	{
		m = -2;
		while (++m <= 1)
			if (value_at(cub, i + m, j + n) == ' ')
				ft_perror("Map is not properly closed!", ft_clean(cub, ERROR));
	}
}

void	check_map(t_cub *cub)
{
	int		i;
	int		j;

	j = -1;
	while (++j < cub->rows_nb)
	{
		i = -1;
		while (++i < cub->map[j].columns)
		{
			if (ft_strnchar("02NEWS", (value_at(cub, i, j))))
				check_map_element(cub, i, j);
			else if (!ft_strnchar("012NEWS ", value_at(cub, i, j)))
				ft_perror("Forbidden Characters in Map!", ft_clean(cub, ERROR));
		}
	}
}

void	check_all(t_cub *cub)
{
	check_map(cub);
	check_camera(cub);
}
