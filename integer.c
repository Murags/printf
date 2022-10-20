#include "main.h"
/**
 * print_int - prints integer
 * @ap: argument list passed to the function
 *
 * Return: size
 */
int print_int(va_list ap)
{
	long int num;
	int next_sum, counter = 0, next;

	num = va_arg(ap, int);

	if (num < 0)
	{
		num *= -1;
		_putchar(45);
		counter++;
	}
	if (num >= 0 && num <= 9)
	{
		_putchar(num + 48);
		counter++;
	}
	if (num > 9)
		next = 10;
	while (num / next > 9)
	{
		next *= 10;
	}
	while (next > 0)
	{
		next_sum = num / next;
		num = num % next;
		_putchar(next_sum + 48);
		next = next / 10;
		counter++;
	}
	return (counter++);
}
