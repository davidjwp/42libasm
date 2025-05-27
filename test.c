#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern int		ft_strlen(const char* );
extern char		ft_strcpy(char*, const char*);
extern int		ft_strcmp(const char*, const char*);
extern size_t	ft_write(unsigned int, const char*, size_t);
extern size_t	ft_read(unsigned int, char*, size_t);
extern char*	ft_strdup(const char*);

#define HELP "./test \033[34mtype\033[0m arg1\n\033[34mlen - cpy - cmp - wrt - read - dup\033[0m\n"

char *test_type[] = {"len", "cpy", "cmp", "wrt", "read", "dup", "del", NULL};

char  *err_type[] = {
	"wrong arguments",
	"empty string",
	"wrong type",
	"alloc error",
	"wrong num arguments",
	"open failed",
};

enum {
	LEN = 0,
	CPY,
	CMP,
	WRT,
	READ,
	DUP,
	DEL,
	NUL
};

void error(char *err)
{
	write(1, "\033[41mError: ", 13);
	write(1, err, strlen(err));
	write(1, "\033[0m\n", 6);
	write(1, HELP, strlen(HELP));
	exit(1);
}

void test_strlen(char *str)
{
	printf("strlen %li\n", strlen(str));
	printf("ft_strlen %i\n", ft_strlen(str));
}

void test_strcpy(char *str)
{
	unsigned siz = strlen(str);
	char *dest = malloc((sizeof(char) * siz) + 1);
	if (!dest)
		error(err_type[3]);

	bzero(dest, siz);
	strcpy((char *)dest, (const char*)str);
	printf("strcpy %s %li\n", (char *)dest, strlen((char *)dest));
	
	bzero(dest, siz);
	ft_strcpy((char *)dest, (const char*)str);
	printf("ft_strcpy %s %li\n", (char *)dest, strlen((char *)dest));
	
	free(dest);
}

void test_strcmp(char *s1, char *s2)
{
	printf("strcmp %i\n", strcmp(s1, s2));
	printf("ft_strcmp %i\n",ft_strcmp(s1, s2));
}

void test_write(char *str)
{
	int fd = open("write_test_file", O_CREAT | O_RDWR | O_APPEND, 0644);

	if (fd < 0)
		return (error(err_type[5]));

	printf("\nwrite to stdout %li\n", write(STDOUT_FILENO, str, strlen(str)));
	printf("\nft_write to stdout %li\n", ft_write(STDOUT_FILENO, str, strlen(str)));

	printf("\nwrite to file %li\n", write(fd, str, strlen(str)));
	printf("\nft_write to stdout %li\n", ft_write(fd, str, strlen(str)));

	printf("\nwrite to err %li\n", write(-1, str, strlen(str)));
	printf("\nft_write to err %li\n", ft_write(-1, str, strlen(str)));

	close(fd);
}

void test_read(void)
{
	char buf[4096];
	int fd = open("./test.c", O_RDWR | O_APPEND);
	int fd_read = open("read", O_CREAT | O_RDWR | O_APPEND, 00644);
	int fd_ft_read = open("ft_read", O_CREAT | O_RDWR | O_APPEND, 00644);

	//read from file
	printf("read from file %li buf -> ./read\n", read(fd, buf, 4096));
	write(fd_read, buf, strlen(buf));
	lseek(fd, 0, SEEK_SET);
	bzero(buf, strlen(buf));
	printf("\033[34mft_read from file %li buf -> ./ft_read\n", ft_read(fd, buf, 4096));
	write(fd_ft_read, buf, strlen(buf));

	//read from STDIN
	bzero(buf, ft_strlen(buf));
	printf("\033[34mread from stdin %li buf = \033[0m%s\n", read(STDIN_FILENO, buf, 4096), buf);
	bzero(buf, ft_strlen(buf));
	printf("\033[34mft_read from stdin %li buf = \033[0m%s\n", ft_read(STDIN_FILENO, buf, 4096), buf);
	
	//error
	bzero(buf, ft_strlen(buf));
	printf("read err %li buf = %s\n", read(-1, buf, 4096), buf);
	bzero(buf, ft_strlen(buf));
	printf("ft_read err %li buf = %s\n", ft_read(-1, buf, 4096), buf);

	close(fd);
	close(fd_read);
	close(fd_ft_read);
}

void test_strdup(char *str)
{
	
	void* dup = strdup(str);
	void* dup2 = ft_strdup(str);

	printf("strdup %s %li\n", (char*)dup, strlen(dup));
	printf("strdup %s %li\n", (char*)dup2, strlen(dup2));

	free(dup);
	free(dup2);
}

unsigned int find(char *avt)
{
	unsigned int i = 0;

	while (test_type[i] && strcmp(avt, test_type[i]))
		i++;

	return (i);
}

int main(int ac, char **av)
{
	if (ac < 2)
		error(err_type[0]);

	switch(find(av[1]))
	{
		case LEN:
			if (ac < 3)
				error(err_type[4]);
			test_strlen(av[2]);
			break ;
		case CPY:
			if (ac < 3)
				error(err_type[4]);
			test_strcpy(av[2]);
			break ;
		case CMP:
			if (ac < 4)
				error(err_type[4]);
			test_strcmp(av[2], av[3]);
			break ;
		case WRT:
			if (ac < 3)
				error(err_type[4]);
			test_write(av[2]);
			break ;
		case READ:
			test_read();
			break ;
		case DUP:
			if (ac < 3)
				error(err_type[4]);
			test_strdup(av[2]);
			break ;
		case DEL:
			remove("./read");
			remove("./ft_read");
			break ;
		case NUL:
			error(err_type[2]);
	}

	return (0);
}