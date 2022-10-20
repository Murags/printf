#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);
int _printf(const char *format, ...);
int (*get_func(const char format))(va_list);
int print_hex(unsigned int n, unsigned int c);

/**
 * struct select - defines a structure for symbols and functions
 * @ident:format specifier
 * @f: printing function
 */
typedef struct select
{
	char ident;
	int (*f)(va_list arg);
} selector;

int print_char(va_list ap);
int print_string(va_list ap);
int print_int(va_list ap);
int print_int(va_list ap);
int decimaltobinary(va_list ap);
int print_unsigned_int(va_list ap);
int print_address(va_list ap);
int print_R(va_list ap);
int print_X(va_list ap);
int print_x(va_list ap);
int print_o(va_list ap);
int print_u(va_list ap);

#endif /*MAIN_h*/
