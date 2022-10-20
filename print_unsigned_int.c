#include "main.h"

/**
 * print_unsigned_int - prints an unsigned in in decimal notation
 * @ap: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_unsigned_int(va_list ap)
{
	unsigned int a[10];
	unsigned int i, m, n, sum;
	int count;

	n = va_arg(ap, unsigned int);
	m = 1000000000; /* (10 ^ 9) */
	a[0] = n / m;
	for (i = 1; i < 10; i++)
	{
		m /= 10;
		a[i] = (n / m) % 10;
	}
	for (i = 0, sum = 0, count = 0; i < 10; i++)
	{
		sum += a[i];
		if (sum || i == 9)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
