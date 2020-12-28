/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:55:29 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/28 17:55:30 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

t_bool	ft_strnchar(const char *str, char c)
{
	int		i = -1;
	while (str[++i])
		if (str[i] == c)
			return (true);
	return (false);
}