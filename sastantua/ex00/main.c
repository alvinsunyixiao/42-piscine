#include <stdlib.h>
#include <unistd.h>

int ft_putchar(char c) {
	write(1, &c, 1);
	return (0);
}

void sastantua(int size);

int main(int argc, char **argv) {
	if (argc != 2)
		return (0);
	else {
		int size;
		if (!(size = atoi(argv[1])))
			return (0);
		else
			sastantua(size);
	}
	return (0);
}
