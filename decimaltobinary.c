#include "main.h"
/**
 * decimaltobinary - converts decimal to binary
 * @ap: argument parameters
 * Return: size
 */
int decimaltobinary(va_list ap)
{
	long int num = va_arg(ap, unsigned int), binaryNum[32], i = 0, j, size = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		binaryNum[i++] = num % 2;
		num /= 2;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar((binaryNum[j] + 48));
		size++;
	}
	return (size);
}
