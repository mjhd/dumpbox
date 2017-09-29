#include <unistd.h>
#include <stdlib.h>

void  ft_putchar(char c)
{
    write(1, &c, 1);
}

int main() {
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * 5);

    while(i < 4)
    {
        char output = ('a' + i);
        str[i] = output;
        i++;
    }
    str[i] = '\0';
    while(i > 0)
    {
        ft_putchar(str[i - 1]);
        i--;
    }
    ft_putchar('\n');
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
    ft_putchar((i + '0'));

    return 0;
}