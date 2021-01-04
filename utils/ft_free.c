/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:54:48 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 16:40:48 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	ft_free(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}

void	ft_free_2d(t_str **str)
{
	int		i;

	i = 0;
	while (str && *str && str[0][i])
		free(str[0][i++]);
	free(*str);
}
