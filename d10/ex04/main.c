#include <stdlib.h>
#include <stdio.h>

int check(char *str)
{
	if (str[0] == 'a')
		return (1);
	else
		return (0);
}

int ft_count_if(char **tab, int(*f)(char*));

int main()
{
	char **s;
	s = (char**)malloc(sizeof(char*) * 3);
	s[0] = "ass";
	s[1] = "add";
	s[2] = "acc";
	s[3] = 0;
	printf("%d\n",ft_count_if(s,&check));
	return 0;
}
