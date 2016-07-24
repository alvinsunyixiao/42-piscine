#include <stdio.h>

int		match(char *s1, char *s2);

int main(int argc, char **argv)
{
	printf("%d\n", match(argv[1], argv[2]));
	return 0;
}
