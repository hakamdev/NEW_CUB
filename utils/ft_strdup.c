/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:55:07 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/29 18:39:28 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

char	*ft_strdup(const char *s)
{
	char	*ss;
	size_t	lens;
	size_t	i;

	i = 0;
	lens = ft_strlen(s);
	if (!(ss = (char *)malloc((lens + 1) * sizeof(char))))
		return (NULL);
	while (i < lens)
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
