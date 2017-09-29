#include <unistd.h>
#include <stdlib.h>

void  ft_putchar(char c)
{
    write(1, &c, 1);
}
/*
void    ft_putstr(*str)
{
    char *pnt;

    *pnt = *str;
    while(*str++)
        ft_putchar(*pnt++);
}
*/

void    ft_putnum(int num)
{
    while (num)
    {
        ft_putchar((num % 10) + '0');
        num -= (num % 10);
        num /= 10;
    }
}

int     ft_str_cnt_put(char *c)
{
    int strlen;

    strlen = -1;
    ft_putchar(*c);
    while (*c++)
    {
        ft_putchar(*c);
        strlen++;
    }
    ft_putchar(':');
    ft_putchar('\t');

    return ++strlen;
}

int main(int argc, char **argv)
{
    char *str;
    int i;

    i = 1;
    //char string1[6] = "hello\0";
    while(argv[i])
    {
        ft_putnum(ft_str_cnt_put(argv[i++]));
        ft_putchar('\n');
    }
    //string1[6] = '\0';  -> FUCK NO!! -> Save lines save lives...
    //char *str;
    //str = string1;


    return 0;
}