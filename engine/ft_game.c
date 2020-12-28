/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:51:50 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/28 18:54:16 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

int		main(int ac, t_str *av)
{
    t_cub cub;

	init_game(&cub, ac, av);
	if (cub.screenshot)
		exit(0);
	mlx_hook(cub.window, EV_KEY_PRESSED, 1L << 0, event_key_pressed, &cub);
	mlx_hook(cub.window, EV_KEY_RELEASED, 1L << 1, event_key_released, &cub);
	mlx_loop_hook(cub.mlx, event_game_loop, &cub);
	mlx_loop(cub.mlx);
	return (SUCCESS);
}