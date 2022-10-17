#include "main.h"

/**
 * _printf.c - prints anything
 * @format: variable type
 * Return: returns integer
 */

int _printf(const char *format, ...)
{
int (*func)(va_list, flags_t *);
const char *ptr;
va_list list;
flags_t flags = {0, 0, 0};
register int count = 0;
va_start(list, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (ptr = format; *ptr; ptr++)
{
if (*ptr == '%')
{
ptr++;
if (*ptr == '%')
{
count += _putchar('%');
} while (get_flag(*ptr, &flags));
ptr++;
func = get_print(*ptr);
count += (func) ? func(list, &flags) : _printf("%%%c", *ptr);
}
else
count += _putchar(*ptr);
}
_putchar(-1);
va_end(list);
return (count);
}
