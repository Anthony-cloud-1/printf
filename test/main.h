#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int parse_format(const char *format, va_list args);
int print_integer(int num);
int print_unsigned_recursive(unsigned int num);
int print_octal_recursive(unsigned int num);
int print_pointer(void *ptr);
int print_hexadecimal(unsigned int num, int uppercase);
int print_char(int c);
int print_string(char *str);
int print_int(int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int print_ptr(void *ptr);
int print_binary(unsigned int n);
int print_custom_string(char *str);
int _putchar(char c);
#endif /* MAIN_H */
