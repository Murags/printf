#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: string to be printed in a specifc format
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, size = 0;
	va_list ap;

	if (!format)
		return (-1);
	va_start(ap, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				size++;
				i++;
			}
			else if (get_func(format[i + 1]) != NULL)
			{
				size += (get_func(format[i + 1]))(ap);
				i++;
			}
			else
			{
				_putchar(format[i]);
				size++;
			}
		}
		else
		{
			_putchar(format[i]);
			size++;
		}
	}
	return (size);
	va_end(ap);
}
