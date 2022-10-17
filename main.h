#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct flags - struct containing flags to turn on for any
 * flag specifier passed to _printf
 * @plus: flag for '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct  flags
{
  int plus;
  int space;
  int hash;
} flags_t;

/**
 * struct printer - struct to handle print operations
 * @c: format sspecifier
 * @print: pointer to print function
 */
typedef struct printer
{
  char c;
  int (*print)(va_list arg, flags_t *f); 
} printer_t;

/* print-nums */
int print_int(va_list l, flags_t *print);
void print_num(int n);
int print_unsigned(va_list l, flags_t *print);
int count_digit(int i);

/* print_bases */
int print_hex(va_list l, flags_t *print);
int print_hex_big(va_list l, flags_t *print);
int print_binary(va_list l, flags_t *print);
int print_octal(va_list l, flags_t *print);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* get-print */
int (*get_print(char s))(va_list, flags_t *);

/* get_flag */
int get_flag(char s, flags_t *print);

/* get_alpha */
int print_string(va_list l, flags_t *print);
int print_char(va_list l, flags_t *print);

/* write_funcs*/
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list l, flags_t *print);
int print_rev(va_list l, flags_t *print);
int print_bigS(va_list l, flags_t *print);

/* print_address */
int print_address(va_list l, flags_t *print);

/* print-percent */
int print_percent(va_list l, flags_t *print);

#endif /*MAIN_H*/