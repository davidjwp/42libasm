#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int fd = open("./t.c", O_CREAT | O_RDWR | O_APPEND, 0644);
	char buf[4096];
	if (fd == -1) return (1);

	read(fd, buf, 4096);
	read(fd, buf, 4096);
	printf("%s\n", buf);
	close(fd);
	return (0);
}

