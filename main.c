#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	char	*line;
	int	i;
	int	ret;

	i = 0;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	while(i < 50)
	{
		line = (char *)malloc(sizeof(*line) * 1);
		ret = get_next_line(fd, &line);
		printf("|%s|\n", line);
		i++;
	}
}
