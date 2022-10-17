#include "main.h"

/**
 * print_hex - print hexadecimal number
 * @l: variable list
 * @print: parameter
 * Return: int
 */
int print_hex(va_list l, flags_t *print)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 16, 1);
int count = 0;
if (print->hash == 1 && str[0] != '0')
count += _puts("0x");
count += _puts(str);
return (count);
}

/**
 * print_hex_big - print big hexadecimal number
 * @l: variable list
 * @print: parameter
 * Return: int
 */
int print_hex_big(va_list l, flags_t *print)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 16, 0);
int count = 0;
if (print->hash == 1 && str[0] != '0')
count += _puts("0x");
count += _puts(str);
return (count);
}

/**
 * print_binary - print binary number
 * @l: variable list
 * @print: parameter
 * Return: int
 */
int print_binary(va_list l, flags_t *print)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 2, 0);
(void)print;
return (_puts(str));
}

/**
 * print_octal - print octal number
 * @l: variable list
 * @print: parameter
 * Return: int
 */
int print_octal(va_list l, flags_t *print)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 8, 0);
int count = 0;
if (print->hash == 1 && str[0] != '0')
count += _putchar('0');
count += _puts(str);
return (count);
}
