/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:41:41 by anazri            #+#    #+#             */
/*   Updated: 2019/07/17 13:42:57 by anazri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_lire(const int fd, char **line)
{
	int		con;
	char	*buf;
	char	*tmp;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	con = read(fd, buf, BUFF_SIZE);
	if (con > 0)
	{
		buf[con] = '\0';
		if (!(tmp = ft_strjoin(*line, buf)))
			return (-1);
		free(*line);
		*line = tmp;
		free(buf);
	}
	if (con == 0)
		free(buf);
	return (con);
}

int			get_next_line(const int fd, char **line)
{
	int			con;
	static char	*buf;
	char		*tmp;

	if (((!buf && (!(buf = ft_strnew(BUFF_SIZE)))) || fd < 0 || BUFF_SIZE <= 0))
		return (-1);
	tmp = ft_strchr(buf, 10);
	while (!tmp)
	{
		con = ft_lire(fd, &buf);
		if (con == 0 && !ft_strlen(buf))
			return (0);
		if (con == 0)
			ft_strcat(buf, "\n");
		if (con < 0)
			return (-1);
		else
			tmp = ft_strchr(buf, 10);
	}
	if (!(*line = ft_strsub(buf, 0, ft_strlen(buf) - ft_strlen(tmp))))
		return (-1);
	ft_strcpy(buf, tmp + 1);
	return (1);
}
