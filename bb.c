#include <unistd.h>
#include <stdlib.h>

void  ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv) {
    char *str;
    int i = 0;

    while(argv[1][i] != '\0')
    {
        i++;
    }

    i++;
    str = calloc(i, sizeof(char) * i);
    i = 0;

    while(argv[1][i] != '\0')
    {
        ft_putchar(str[i] + '0');
        str[i] = argv[1][i];
        i++;
    }
    str[i] = '\0';

    i = 0;

    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }

    ft_putchar('\n');
    ft_putchar((i + '0'));
    free(str);

    return 0;
}