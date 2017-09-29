#include <stdio.h>

int change_num(int *c)
{
    int val = *c;
    int **pnt = &c;
    val *= 2;
    **pnt = 48;
    return ((val * 2));
}

int main(void) {

    int a = 3;
    int *b = &a;
    int **c = &b;
    *b = 6;
    *b = 12;
    **c = 24;
    printf("%d", change_num(*c));

    printf("%d", a);

    return 0;
}
