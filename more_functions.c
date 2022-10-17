#include "main.h"

/**
 * get_flag - gets the flag of format
 * 
 * @s: character
 * @print: parameter
 * Return: int 
 */
int get_flag(char s, flags_t *print)
{
int i = 0;
switch (s)
{
case '+':
print->plus = 1;
i = 1;
break;
case ' ':
print->space = 1;
i = 1;
break;
case '#':
print->hash = 1;
i = 1;
break;
}
return (i);
}

/**
 * print_bigS - print bigS
 * 
 * @l: variable list 
 * @print: parameter
 * Return: int 
 */
int print_bigS(va_list l, flags_t *print)
{
int i, count = 0;
char *result;
char *s = va_arg(l, char *);
(void)print;
if(!s)
return (_puts("(null)"));
for (i = 0; s[i]; i++)
{
if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
{
_puts("\\x");
count += 2;
result = convert(s[i], 16, 0);
if (!result[1])
count += _putchar('0');
count += _puts(result);
}
else
count += _putchar(s[i]);
}
return (count);
}

/**
 * print_rev - print reversed string
 * 
 * @l: variable list 
 * @print: parameter
 * Return: int 
 */
int print_rev(va_list l, flags_t *print)
{
int i = 0, j;
char *s = va_arg(l, char *);
(void)print;
if (!s)
s = "(null)";
while (s[i])
i++;
for (j = i - 1; j >= 0; j--)
_putchar(s[j]);
return (i);
}

/**
 * print_rot13 - print rot13
 * 
 * @l: variable list 
 * @print: parameter
 * Return: int 
 */
int print_rot13(va_list l, flags_t *print)
{
int i, j;
char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
char *str = va_arg(l, char *);
(void)print;
for (j = 0; str[j]; j++)
{
if (str[j] < 'A' || (str[j] > 'Z' && str[j] < 'a') || str[j] > 'z')
_putchar(str[j]);
else
{
for (i = 0; i <= 52; i++)
{
if (str[j] == rot13[i])
_putchar(ROT13[i]);
}
}
}
return (j);
}

/**
 * print_percent - print percent
 * 
 * @l: variable list 
 * @print: parameter
 * Return: int 
 */
int print_percent(va_list l, flags_t *print)
{
(void)l;
(void)print;
return (_putchar('%'));
}

/**
 * get_print - Get the print object
 * 
 * @s: character format 
 * Return: integer
 */
int (*get_print(char s))(va_list, flags_t *)
{
printer_t func[] = {
{'i', print_int},
{'s', print_string},
{'c', print_char},
{'d', print_int},
{'u', print_unsigned},
{'x', print_hex},
{'X', print_hex_big},
{'b', print_binary},
{'o', print_octal},
{'R', print_rot13},
{'r', print_rev},
{'S', print_bigS},
{'p', print_address},
{'%', print_percent}
};
int flags = 14;
register int i;
for (i = 0; i < flags; i++)
if (func[i].c == s)
return (func[i].print);
return (NULL);
}