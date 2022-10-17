#include "main.h"

/**
 * print_string - prints a string
 * @l: variable list
 * @print: parameter
 * Return: int
 */
int print_string(va_list l, flags_t *print)
{
char *str;
str = va_arg(l, char *);
(void)print;
if (!str)
    str = "(null)";
return (_puts(str));
}
