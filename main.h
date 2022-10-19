#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

int _putchar(char c);
int _printf(const char *format, ...);

/**
 * struct select - defines a structure for symbols and functions
 * @ident:format specifier
 * @f: printing function
 */
typedef struct select
{
	char *ident;
	int (*f)(va_list arg);
} selector;
int print_char(va_list ap);
int print_string(va_list ap);
int print_int(va_list ap);
int decimaltobinary(va_list ap);
#endif
