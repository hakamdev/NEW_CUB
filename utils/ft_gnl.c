/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:22:33 by ehakam            #+#    #+#             */
/*   Updated: 2021/01/04 17:01:27 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static int	is_fd_valid(int fd)
{
	return (((fd) >= 0 && (fd) <= (MAXFD)) ? 1 : 0);
}

static int	ft_find_index(const char *s, char c)
{
	int		i;

	if (s)
	{
		i = 0;
		while ((char)s[i])
		{
			if ((char)s[i] == c)
				return (i);
			i++;
		}
	}
	return (ERR);
}

static int	ft_handle_nl(char **v_line, char **v_temp, char **v_rest)
{
	int		nl_index;
	char	*v_addup;

	nl_index = ft_find_index(*v_temp, NL);
	if (nl_index != ERR)
	{
		if (!(v_addup = ft_strsub(v_temp, 0, nl_index)))
			return (ERR);
		if (!(*v_line = ft_strjoin(*v_line, v_addup)))
			return (ERR);
		if (!(*v_rest = ft_strdup(&v_temp[0][nl_index + 1])))
			return (ERR);
		ft_free(&v_addup);
		ft_free(v_temp);
		return (1);
	}
	return (INULL);
}

static int	ft_handle_rest(char **v_line, char **v_temp, char **v_rest)
{
	int		ret;

	if (*v_rest)
	{
		if (ft_find_index(*v_rest, NL) > ERR)
		{
			ft_free(v_temp);
			*v_temp = *v_rest;
			if ((ret = ft_handle_nl(v_line, v_temp, v_rest)) != INULL)
				return (ret);
		}
		else
		{
			if (!(*v_line = ft_strjoin(*v_line, *v_rest)))
				return (ERR);
			ft_free(v_rest);
		}
	}
	return (INULL);
}

int			get_next_line(int fd, char **line)
{
	static char	*rest[MAXFD];
	char		*temp;
	int			sread;
	int			ret;

	if (!line || !is_fd_valid(fd) || read(fd, NULL, 0) == ERR
	|| !(temp = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERR);
	sread = 0;
	if (!(*line = ft_strdup("")))
		return (ERR);
	if ((ret = ft_handle_rest(line, &temp, &rest[fd])) != INULL)
		return (ret);
	while ((sread = read(fd, temp, BUFFER_SIZE)) > INULL)
	{
		temp[sread] = CNULL;
		if (ft_find_index(temp, NL) > ERR)
			if ((ret = ft_handle_nl(line, &temp, &rest[fd])) != INULL)
				return (ret);
		if (!(*line = ft_strjoin(*line, temp)))
			return (ERR);
	}
	if (!sread)
		ft_free(&temp);
	return (sread > 0 ? 1 : sread);
}
