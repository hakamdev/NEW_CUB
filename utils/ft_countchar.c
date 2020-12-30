/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:59:05 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/30 17:09:31 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

int		ft_countchar(const t_str str, char c)
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
