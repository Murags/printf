#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

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
	void (*f)(va_list arg);
} selector;
void print_char(va_list ap);
void print_string(va_list ap);
void print_int(va_list ap);
void decimaltobinary(va_list ap);
#endif
