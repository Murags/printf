#include "main.h"
/**
*get_func - produces output according to format
*
*@format: string to be printed
*
*Return: number of charaters printed else 0
*/
int (*get_func(const char format))(va_list)
{
	selector(array[]) = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};

	int i;

	for (i = 0; array[i].ident != '\0'; i++)
	{
		if (array[i].ident == format)
		{
			return (array[i].f);
		}
	}
	return (0);
}
