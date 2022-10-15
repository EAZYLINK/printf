#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

typedef struct printer
{
  char *symbol;
  void (*print)(va_list arg); 
} printer_t;

void print_char(va_list arg);
void print_int(va_list arg);
void print_float(va_list arg);
void print_string(va_list);
int _putchar(char c);
int _printf(const char *format, ...);

#endif /*MAIN_H*/