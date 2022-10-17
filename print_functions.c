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
 * _puts - prints a string to stdout
 * @str: pointer to the string
 * Return: number of characters written
 */
int _puts(char *str)
{
register int i;
for (i = 0; str[i] != '\0'; i++)
_putchar(str[i]);
return (i);
}

/**
 * print_char - print character
 * 
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

/**
 * print_int - print integer
 * 
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
 * 
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
 * 
 * @l: variable list 
 * @print: parameter
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
 * 
 * @n: integer 
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

/**
 * print_string - prints a string
 * 
 * @l: variable list 
 * @print: parameter
 * Return: int 
 */
int print_string(va_list l, flags_t *print)
{
char *str;
str = va_arg(l, char *);
(void)print;
if(!str)
str = "(null)";
return (_puts(str));
}

/**
 * print_hex - print hexadecimal number
 * 
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
 * 
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
 * 
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
 * 
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

/**
 * print_address - print address of variable
 * 
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
/**
 * convert - converts number and base to string
 * @num: input number
 * @base: given base
 * @lowercase: flag if hex values is needed to be lowercase
 * Return: result string
 */

char *convert(unsigned long int num, int base, int lowercase)
{
static char *rep;
static char buffer[50];
char *ptr;

rep = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do 
{
*--ptr = rep[num % base];
num /= base;
}
while (num != 0);
return (ptr);
}

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
 * @Return: int(*)(va_list, flags_t*) 
 */
int(*get_print(char s))(va_list, flags_t *)
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