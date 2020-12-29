/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:57:26 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/28 18:59:45 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	r;
	char	*s;

	i = 0;
	r = 0;
	s = (char *)str;
	while ((*s > 0 && *s <= ' ' && *s != 27))
		s++;
	if (*s == '+')
		s++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (r < 2147483647)
			r = r * 10 + (s[i] - '0');
		i++;
	}
	while (s[i])
	{
		if (!(s[i] >= 0 && s[i] <= ' '))
			return (ERR);
		i++;
	}
	return ((r > 2147483647) ? 2147483647 : r);
}
