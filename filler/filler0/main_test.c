#include "libft/Libft/libft.h"

int	main()
{
	const char *t = " ";
	char **res;
	int ret;

	res = ft_strsplit(t, ' ');
	while (*res != NULL)
	{
		printf("<%s>\n", *res);
		res++;
	}
	dprintf(2, "prout\n");
	ft_atoi(res[2]);
	printf("%d\n", ret);
	return 0;
}