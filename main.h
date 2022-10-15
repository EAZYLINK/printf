#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

typedef struct printer
{
  char *symbol;
  int (*print)(va_list arg); 
} printer_t;

int print_char(va_list arg);
int print_int(va_list arg);
int print_float(va_list arg);
int print_string(va_list);
int _putchar(char c);
int _printf(const char *format, ...);

#endif /*MAIN_H*/