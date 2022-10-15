#include "main.h"

/**
 * _putchar - prints character
 * @c: character to be printed
 * Return: int
 */

int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * print_char - prints characters
 * @arg: list of arguments
 * Return: int
 */

int print_char(va_list arg)
{
char c;
c = va_arg(arg, char);
_putchar(c);
}

/**
 * print_int - prints integers
 * @arg: list of arguments
 * Return: int
*/

int print_int(va_list arg)
{
long int num;
int count = 0, temp, base;
num = va_arg(arg, int);
if (num < 0)
{
num *= -1;
_putchar(45);
count++;
}
if (num >= 0 && num <= 9)
{
_putchar(num + 48);
count++;
}
if (num > 9)
{
base = 10;
while (num / base > 9)
{
base *= 10;
}
while (base > 0)
{
temp = num / base;
num = num % base;
_putchar(temp + 48);
base = base / 10;
count++;
}
}
return (count);
}

/**
 * print_string - prints string
 * @arg: list of arguments
 * Return: int
 */

int print_string(va_list arg)
{
char *str;
int count;
str = va_arg(arg, char*);
if (str == NULL)
{
write(1, "(null)", 6);
return (6);
}
else
{
for (count = 0; str[count] != '\0'; count++)
{
_putchar(str[count]);
}
}
return (count);
}