
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 80
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

 int	get_next_line(const int fd, char **line);
 int	search(char **str, char **line, int *count);

#endif
