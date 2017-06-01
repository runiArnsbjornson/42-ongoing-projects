#include "libft.h"

int	main()
{
	int *next;

	next = (int *)ft_memalloc(sizeof(int) * 4);
	ft_putinttab(next, 3);
	return 0;
}