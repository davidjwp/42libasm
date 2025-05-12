#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int ft_strlen(char* );
extern char ft_strcpy(char*, const char*);
extern int ft_strcmp(char*, char*);


#define HELP "./test \033[34mtype\033[0m arg1\n\033[34mlen - cpy - cmp - \033[0m\n"

char test_type[7][5] = {"len", "cpy", "cmp", "wrt", "read", "dup", 0};

char  err_type[5][20] = {
	"wrong arguments",
	"empty string",
	"wrong type",
	"alloc error",
	"wrong num arguments"
};

enum {
	LEN = 0,
	CPY,
	CMP,
	WRT,
	READ,
	DUP,
	NEG
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
	int res1 = 0, res2 = 0;

	printf("strcmp %i\n", strcmp(s1, s2));
	printf("ft_strcmp %i\n",ft_strcmp(s1, s2));
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
	if (ac < 3)
		error(err_type[0]);

	switch(find(av[1]))
	{
		case LEN:
			test_strlen(av[2]);
			break ;
		case CPY:
			test_strcpy(av[2]);
			break ;
		case CMP:
			if (ac < 4)
				error(err_type[4]);
			test_strcmp(av[2], av[3]);
			break ;
		case WRT:
		case READ:
		case DUP:
		case NEG:
			error(err_type[2]);
	}
	return (0);
}