#include "main.h";

/**
 * _printf.c - prints anything
 * @format: variable type
 * Return: returns integer
 */

int _printf(const char *format, ...)
{
va_list list;
unsigned int i, char_num = 0;
if (!format)
return (-1);
va_start(list, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
if (format[i + 1] == '\0')
return (-1);
else if(format[i + 1] == '%')
{
_putchar('%');
char_num++;
i++;
}
else if (cmp_func(format[i + 1]) != NULL)
{
char_num += (cmp_func(format[i + 1]))(list);
i++;
}
else
{
_putchar(format[i]);
char_num++;
}
}
else {
    _putchar(format[i]);
    char_num++;
}
}
va_end(list);
return (char_num);
}

/**
 * cmp_func - compares function
 * @a: character
 * Return: integer
 */

int (*cmp_func(const char a))(va_list)
{
printer_t printf[] = {
    {'c', print_char},
    {'s', print_string},
    {'d', print_int},
    ('i', print_int),
    {'\0', NULL}
};

int count;
for (count = 0; printf[count].symbol != '\0'; count++)
{
if (printf[count].symbol == a)
{
return (printf[count].print);
}
}
return (0);
}