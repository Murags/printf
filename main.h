#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
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
