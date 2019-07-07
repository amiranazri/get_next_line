
#include "get_next_line.h"

static int	ft_lire(const int fd, char **line)
{
	int 	con;
	char	*buf;
	char	*temp;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	con = read(fd, buf, BUFF_SIZE);
	if (con > 0)
	{
		if (!(temp = ft_strjoin(*line, buf)))
			return (-1);
		ft_strdel(line);
		*line = temp;
	}
	ft_strdel(&buf);
	return (con);
}

int	get_next_line(const int fd, char **line)
{
	int		con;
	char		*str;
	static char	*temp;

	if ((!(temp = ft_strnew(BUFF_SIZE)) || fd < 0 || BUFF_SIZE == 0))
		return (-1);
	str = NULL;
	while (str == NULL)
	{
		con = ft_lire(fd, line);

		if (con == 0)
		{
			if (!ft_strlen(temp))
				return (0);
			ft_strcat(temp, "\n");
		}
		if (con < 0)
			return (-1);
		else
			str = ft_strchr(temp, '\n');
	}
	if (!(*line = ft_strsub(temp, 0, ft_strlen(temp) - ft_strlen(str))))
		return (-1);
	ft_strcpy(temp, str + 1);
	return (1);
}
