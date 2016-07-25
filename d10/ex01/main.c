#include <stdio.h>

int ft_putchar(char c)
{
	printf("%c",c);
	return 0;
}

void ft_putnbr(int nb);

void ft_foreach(int *tab, int length, void(*f)(int));

int main()
{
	int a[] = {0,1,2,3,4,5,6};
	ft_foreach(a, 7, &ft_putnbr);
	return 0;
}
