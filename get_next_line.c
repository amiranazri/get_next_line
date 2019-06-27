
int	search(char **str, char **line, int *count)
{
	int i;
	char *hold;

	i = 0;
	while (str[i])
		if (str[i] == '\n')
			hold = ft_strenew(i);
			if (!hold)
				return (-1);

}
 
int	get_next_line(const int fd, char **line)
