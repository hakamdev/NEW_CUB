/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:55:40 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/29 18:37:33 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

char	*ft_strsub(char **s, unsigned int start, size_t n)
{
	char			*ss;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (*s == NULL)
		return (NULL);
	len = ft_strlen(*s);
	if (start > len)
		n = 0;
	if (!(ss = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	while (i < n && start < len)
		*(ss + i++) = *(*s + start++);
	*(ss + i) = '\0';
	return (ss);
}
