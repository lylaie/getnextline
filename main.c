#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd1 = open (av[1], O_RDONLY);
	char *line;
	int r;
	(void)ac;

	while ((r = get_next_line(fd1, &line)) > 0)
	{
		printf("%d [%s]\n", r, line);
		free(line);
	}
	printf("%d [%s]\n", r, line);
	if (r == 0)
		free(line);
	return (19);
}
// touch empty.txt
