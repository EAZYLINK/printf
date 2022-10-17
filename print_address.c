#include "main.h"

/**
 * print_address - print address of variable
 * @l: variable list
 * @print: parameter
 * Return: int
 */
int print_address(va_list l, flags_t *print)
{
char *str;
unsigned long int p = va_arg(l, unsigned long int);
register int count = 0;
(void)print;
if (!p)
return (_puts("(nil)"));
str = convert(p, 16, 1);
count += _puts("0x");
count += _puts(str);
return (count);
}
