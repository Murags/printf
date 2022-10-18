#include "main.h"

void print_int(va_list ap)
{
        unsigned int num, d, counter;
        int n = va_arg(ap, int);

        if (n < 0)
        {
                _putchar(45);
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
        }
}

