#include "main.h"
/**
<<<<<<< HEAD
=======
*get_func - produces output according to format
*
*@format: string to be printed
*@ap: argument parameters
*
*Return: number of charaters printed else 0
*/
int get_func(const char *format, va_list ap)
{
	int i, j, counter = 0, size = 0, arrsize;

	selector funcs[] = {
		{"c", print_char}, {"s", print_string},
		{"d", print_int}, {"i", print_int},
		{"b", decimaltobinary}
	};
	arrsize = sizeof(funcs) / sizeof(funcs[0]);
	for (i = 0; *(format + i) != '\0'; i++)
	{
		j = 0;
		if (*(format + i) == '%')
		{
			i++;
			if (*(format + i) == '\0')
				return (-1);
			while (j < arrsize && (*(format + i) != *(funcs[j].ident)))
				j++;

			if (j < arrsize)
				size = funcs[j].f(ap);
			else if (*(format + i) == '%')
			{
				write(1, (format + i), 1);
				size += 1;
			}
			else
			{
				_putchar('%'), _putchar(*(format + i));
				size += 2;
			}
		}
		else
		{
			write(1, (format + i), 1);
			counter++;
		}
	}
	return (counter + size);
}
/**
>>>>>>> 8bbc3a607091ea2ba8c68d17084a2293dcf8b803
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
