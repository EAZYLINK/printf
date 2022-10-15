#include "main.h"

/**
 * _putchar - prints character
 * @c: character to be printed
 */

int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * print_char - prints characters
 * @arg: list of arguments
 */

void print_char(va_list arg)
{
char c;
c = va_arg(arg, char);
_putchar(c);
}