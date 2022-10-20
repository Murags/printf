#include "main.h"
/**
 * print_int - prints integer
 * @ap: argument list passed to the function
 * Return: Nothing
 */
int print_int(va_list ap)
{
	unsigned int num, d, counter;
	int n = va_arg(ap, int), size = 0;

	if (n < 0)
	{
		_putchar(45);
		size++;
		num = -n;
	}
	else
	{
		num = n;
	}

	d = num;
	counter = 1;

	while (d > 9)
	{
		d /= 10;
		counter = counter * 10;
	}

	for (; counter >= 1; counter /= 10)
	{
		_putchar(((num / counter) % 10) + 48);
		size++;
	}
	return (size);
}
