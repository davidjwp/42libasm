#include <string.h>
#include <stdio.h>



int scmp(const char* ar1, const char* ar2)
{
	while ((*ar1 && *ar2) && !(*ar1 - *ar2))
	{
		ar1++;
		ar2++;
	}
	return (*ar1 - *ar2);
}

int	main(int ac, char **av)
{
	printf("strcmp %i\n", strcmp(av[1], av[2]));
	printf("scmp %i\n",scmp(av[1], av[2]));
	return (0);
}
