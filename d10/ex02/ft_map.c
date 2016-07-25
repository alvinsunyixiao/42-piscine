#include <stdlib.h>

int		*ft_map(int *tab, int length, int(*f)(int))
{
	int *rs;
	int i;

	rs = (int*)malloc(sizeof(int) * length);
	i = -1;
	while (++i < length)
		rs[i] = f(tab[i]);
	return (rs);
}
