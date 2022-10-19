#include "main.h"
/**
 * print_string - prints a string
 * @ap: argument parameters
 *Return: string length success else 6
 */
int print_string(va_list ap)
{
	char *str;
	int len;

	str = va_arg(ap, char *);
	if (str)
	{
		for (len = 0; *(str + len) != '\0'; len++)
			;
		write(1, str, len);
		return (len);
	}
	write(1, "(null)", 6);
	return (6);
}
