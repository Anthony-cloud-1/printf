#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int parse_format(const char *format, va_list args);
int print_string(const char *str);
int print_hex(int value);
int print_integer(int num);
int print_unsigned(unsigned int num);
int print_octal(unsigned int num);
int print_unsigned_recursive(unsigned int num);
int print_octal_recursive(unsigned int num);
int _putchar(char c);
#endif /* MAIN_H */
