/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:55:34 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/11 14:59:47 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	if (!*s1 || !*s2)
		return (s1[i] - s2[i]);
	while (i < n - 1 && s1[i]
			&& s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
