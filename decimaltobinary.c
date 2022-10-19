#include "main.h"
/**
 * decimaltobinary - converts decimal to binary
 * @ap: argument parameters
 * Return: 0
 */
int decimaltobinary(va_list ap)
{
	int num = va_arg(ap, int), binaryNum[32], i = 0, j;

	if (num == 0)
	{
		_putchar('0');
		return (0);
	}

	while (num > 0)
	{
		binaryNum[i++] = num % 2;
		num /= 2;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar((binaryNum[j] + 48));
	return (0);
}
