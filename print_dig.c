#include "main.h"

/**
 * print_digit - helper function used to print out an int
 * @n: the number we want to be printed
 * Return: returns the count number so we can add it to our counter
 */

int print_digit(int n)
{
	int d;
	int count = 0;

	for (d = 1; d <= n; d *= 10)
		;
	while (n > 0)
	{
		d /= 10;
		_putchar(n / d + '0');
		n %= d;
		count++;
	}
	return (count);
}
