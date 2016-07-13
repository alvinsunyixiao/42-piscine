#include <unistd.h>
void ft_putchar(char c) {
    write(1,&c,1);
}

int main() {
    int i;
    for (int i='0';i<='9';i++) {
        ft_putchar(i);
    }
    ft_putchar('\n');
    return 0;
}