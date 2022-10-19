#include "main.h"
/**
*get_func - produces output according to format
*
*@str: string to be printed
*@ap: argument parameters
*
*Return: number of charaters printed else 0
*/
int get_func(const char *format, va_list ap)
{
	int i, j, counter = 0, size = 0;

	selector funcs[] = {
		{"c", print_char},{"s", print_string},
		{"d", print_int},{"i", print_int},
		{"b", decimaltobinary}
	};
	for (i = 0; *(format + i) != '\0'; i++)
	{
		j = 0;
		if (*(format + i) == '%')
		{
			i++;
			if (*(format + i) == '\0')
			{
				_putchar('%');
				size++;
				return (size + counter);
			}
			while (j < 5 && (*(format + i) != *(funcs[j].ident)))
				j++;

			if (j < 5)
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
 * _printf - function that produces output according to a format.
 * @format: string to be printed in a specifc format
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, size;
	va_list ap;

	if (format == NULL)
		return (-1);
	for (i = 0; *(format + i) != '\0'; i++)
		;
	if (i <= 0)
		return (0);

	va_start(ap, format);

	size = get_func(format, ap);

	va_end(ap);

	return (size);
}
