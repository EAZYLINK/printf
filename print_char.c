#include "main.h"

/**
 * print_char - print character
 * @l: variable list
 * @print: parameter
 * Return: int
 */

int print_char(va_list l, flags_t *print)
{
char c = va_arg(l, int);
(void)print;
_putchar(c);
return (1);
}
