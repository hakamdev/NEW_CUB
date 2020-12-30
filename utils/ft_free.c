/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:54:48 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/30 15:40:23 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

void	ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

int		free_2d(t_str *str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		ft_free(str[i++]);
	free(str);
	return (SUCCESS);
}
