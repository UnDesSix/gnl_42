#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		value_return;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		printf("*** %s ***\n", argv[i]);
		j = 0;
		while ((value_return = get_next_line(fd, &line)) > 0)
		{
			printf("return       (%3d) : %s\n", j, line);
			if (line)
				free(line);
			j++;
		}
		printf("final return (%3d) : %s\n", j, line);
		printf("*** RETURN = %d ***\n\n", value_return);
		if (line)
			free(line);
		close(fd);
		i++;
	}
	if (argc == 1)
	{
		fd = 0;
		printf("*** Stdin ***\n");
		while ((value_return = get_next_line(fd, &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
		printf("%s\n", line);
		printf("*** RETURN = %d ***\n\n", value_return);
		free(line);
		close(fd);
		i++;
	}
	return (0);
}


