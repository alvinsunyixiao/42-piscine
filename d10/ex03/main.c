#include <stdlib.h>
#include <stdio.h>

int check(char *str)
{
	if (str[0] == 'a')
		return (1);
	else
		return (0);
}

int 	ft_any(char **tab, int(*f)(char*));

int main()
{
	char **s;
	s = (char**)malloc(sizeof(char*) * 3);
	s[0] = "sss";
	s[1] = "sdd";
	s[2] = "ccc";
	s[3] = 0;
	printf("%d\n",ft_any(s,	&check));
	return 0;
}
