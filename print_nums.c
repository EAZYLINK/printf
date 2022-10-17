#include "main.h"

/**
 * print_int - print integer
 * @l: variable list
 * @print: parameter
 * Return: int
 */
int print_int(va_list l, flags_t *print)
{
int num = va_arg(l, int);
int result = count_digit(num);
if (print->space == 1 && print->plus == 0 && num >= 0)
result += _putchar(' ');
if (print->plus == 1 && num >= 0)
result += _putchar('+');
if (num <= 0)
result++;
print_num(num);
return (result);
}

/**
 * print_unsigned - print unsigned integer
 * @l: variable list
 * @print: parameter
 * Return: int
 */
int print_unsigned(va_list l, flags_t *print)
{
unsigned int u = va_arg(l, unsigned int);
char *str = convert(u, 10, 0);
(void)print;
return (_puts(str));
}

/**
 * print_num - print numbers
 * @n: parameter
 * Return: int
 */
void print_num(int n)
{
unsigned int num;
if (n < 0)
{
_putchar('-');
num = -n;
}
else
num = n;
if (num / 10)
print_num(num / 10);
_putchar((num % 10) + '0');
}

/**
 * count_digit - counts the number of digit
 * @i: integer
 * Return: int
 */
int count_digit(int i)
{
unsigned int d = 0;
unsigned int u;
if (i < 0)
u = i * -1;
else
u = i;
while (u != 0)
{
u /= 10;
d++;
}
return (d);
}
