#include "main.h"
/**
 * print_char - prints a char
 * @ap: argument parameters
 * Return: 1 on success
 */
int print_char(va_list ap)
{
	char output = va_arg(ap, int);

	write(1, &output, 1);
	return (1);
}
