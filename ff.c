#include <unistd.h>
#include <stdlib.h>

void  ft_putchar(char c)
{
    write(1, &c, 1);
}

int main() {
    char *str;
    int i = 0;
    char string1[5] = "hello";
    char *string2;

    while (string1[i])
    {
        i++;
    }

    string2 = (char*)calloc(i, sizeof(char) * i); // Just for the string

    //str = &string2[0];  -> the other way now!
    str = string2;
    i = 0;
    //int myArray[10] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 }; -> THIS DOES
    //str = {'w','e','l','l','d','\0'};    ->  THIS DOESN'T WORK :(
    while(i <= 5)
    {
        char c;
        if (i == 0)
            c = 'w';
        else if (i == 1)
            c = 'o';
        else if (i == 2)
            c = 'r';
        else if (i == 3)
            c = 'l';
        else if (i == 4)
            c = 'd';
        else
            c = 0;
        str[i] = c;
        i++;
    }

    //str = malloc(sizeof(char) * i);  -- NO NEED!
    i = 0;
    while(string1[i])
    {
        ft_putchar(string1[i]);
        i++;
    }
    ft_putchar('\n');
    i = 0;
    while(string2[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
    ft_putchar((i + '0'));

    return 0;
}