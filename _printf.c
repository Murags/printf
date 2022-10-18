#include "main.h"
/**
 * print_char - prints a char
 * @ap: argument parameters
 */
void print_char(va_list ap)
{
	char output = va_arg(ap, int);

	write(1, &output, 1);
}
/**
 * print_string - prints a string
 * @ap: argument parameters
 */
void print_string(va_list ap)
{
	char *str;
	int len;

	str = va_arg(ap, char *);

	for (len = 0; *(str + len) != '\0'; len++)
		;

	write(1, str, len);
}
/**
 * decimaltobinary - converts decimal to binary
 * @ap: argument parameters
 */
void decimaltobinary(va_list ap)
{
	int num = va_arg(ap, int), binaryNum[32], i = 0, j;

	if (num == 0)
	{
		_putchar('0');
		return;
	}

	while (num > 0)
	{
		binaryNum[i++] = num % 2;
		num /= 2;
	}

	for (j = i - 1; j >= 0; j--)
		_putchar((binaryNum[j] + 48));
}
/**
 * _printf - function that produces output according to a format.
 * @format: string to be printed in a specifc format
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, j, counter = 0;
	va_list ap;

	selector funcs[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"b", decimaltobinary}
	};
	if (format == NULL)
		return (-1);

	va_start(ap, format);
	for (i = 0; *(format + i) != '\0'; i++)
	{
		j = 0;
		if (*(format + i) == '%')
		{
			i++;
			while (j < 5 && (*(format + i) != *(funcs[j].ident)))
				j++;

			if (j < 5)
				funcs[j].f(ap);

			else if (*(format + i) == '%')
				write(1, (format + i), 1);
			else
			{
				_putchar('%');
				_putchar(*(format + i));
				counter++;
			}
		}
		else
		{
			write(1, (format + i), 1);
		}
		counter++;
	}
	va_end(ap);
	return (counter);
}
