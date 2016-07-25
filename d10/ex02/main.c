#include <stdio.h>

int add(int a)
{
	return (a * 10);
}

int *ft_map(int *tab, int length, int(*f)(int));

int main()
{
	int a[] = {0,1,2,3,4,5,6};
	int *rs;
	rs = ft_map(a, 7, &add);
	for (int i =0;i<7;i++)
		printf("%d\n", rs[i]);
	return 0;
}
