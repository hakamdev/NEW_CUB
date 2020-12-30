/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:00:13 by ehakam            #+#    #+#             */
/*   Updated: 2020/12/30 17:00:38 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubengine.h"

t_str	ft_lowercase(t_str str)
{
	int		i;
	t_str	new_str;

	i = -1;
	new_str = ft_strdup(str);
	while (new_str && new_str[++i])
		if (new_str[i] >= 'A' && new_str[i] <= 'Z')
			new_str[i] = new_str[i] + 32;
	return (new_str);
}
