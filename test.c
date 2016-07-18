#include <stdio.h>
#include <string.h>


int main() {
    char a[] = "hello";
    char b[] = "hk";
    char *c;
    strcpy(b, a);
    printf("%s\n%s\n",a,b);
    return 0;
}