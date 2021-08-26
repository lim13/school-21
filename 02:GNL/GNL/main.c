#include "get_next_line.h"

int main(void)
{
	char	*line;
	int		fd;
	int		i;

	fd = open("text.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|count=%d| line=|%s|\n", i, line);
		free(line);
	}
	if (line != NULL)
	{
		printf("|count=%d| line=|%s|", i, line);
		free(line);
	}
	return (0);
}