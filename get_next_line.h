
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 80
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft/libft.h"

int		get_next_line(const int fd, char **line);
static int	ft_lire(const int fd, char **line);
#endif
