/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:57:26 by ehakam            #+#    #+#             */
/*   Updated: 2020/10/19 12:12:56 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

int		ft_atoi(const char *str)
{
	int		i;
	unsigned long long	r;
	char	*s;

	i = 0;
	r = 0;
	s = (char *)str;
	while (*s > 0 && *s <= ' ')
	{
		if (*s == 27)
			return (ERROR);
		s++;
	}
	if (*s == '+')
		s++;
	while (s[i] >= '0' && s[i] <= '9')
		r = r * 10 + (s[i++] - '0');
	if (!(*s > 0 && *s <= ' '))
		return (ERROR);
	if (r > 2147483647L)
		return (2147483647);
	return (r);
}
