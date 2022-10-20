#include "main.h"

int print_int(va_list ap)
{
	long int d = 0;
	long int counter = 1;
	long int num = 0;
	int size = 0;

	num = va_arg(ap, int);
	if (num < 0)
	{
		_putchar('-');
		num = -num;
		size++;
	}
	while (counter <= num)
	{
		counter *= 10;
	}
	counter /= 10;
	d = num;
	while (counter > 0)
	{
		d = num / counter;
		_putchar((d % 10) + 48);
		counter /= 10;
		size++;
	}
	if (num == 0)
	{
		_putchar(48);
		size++;
	}
	return (size);
}
