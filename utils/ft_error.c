/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:54:41 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/28 17:54:43 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

int ft_clean(t_cub *cub, int return_code)
{
	return (return_code);
}

int ft_perror(t_str msg, int return_code)
{
	int len;

	len = ft_strlen(msg);
	write(2, "\033[0;31m", 8);
	write(2, "Error: ", 7);
	write(2, msg, len);
	write(2, "\n\n", 2);
	// write(2, "\033[0m", 5);
	exit(return_code);
}