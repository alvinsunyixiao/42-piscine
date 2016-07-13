#include <unistd.h>
void ft_putchar(char c) {
    write(1,&c,1);
}

int main() {
    int i;
    for (i='a';i<='z';i++) {
        ft_putchar(i);
    }
    ft_putchar('\n');
    return 0;
}