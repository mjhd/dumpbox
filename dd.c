#include <stdio.h>



void really_change_char(char *c)
{
    char ***pnt = &c;
    ***pnt = 'c';
    printf("%c", ***pnt);
    //the_final_countdown(*pnt);
}

void change_char(char *c)
{
    char **pnt = &c;
    char ***finalpnt = &pnt;
    **pnt = 'b';
    printf("%c", **pnt);
    really_change_char(*finalpnt);
}

int main() {
    int a = 'a';
    char *b = &a;
    char **c = &b;
    printf("%c", **c);

    change_char(*c);
    **c = 'd';

    printf("%c", a);

    return 0;
}