#include "main.h"
#include <unistad>

/**
 * print integer
 * @n: integer to print
 * Description: this problem starts from the very first digit or index
 * and then prints till the end is reached
 * this code takes max int and min int into account
 * Return: an int, the count
 */

int print_number(int i)
{
	int dig = i;
	int count = 0;
	int places = 1;

	while (dig / 10)
	{
		dig /= 10;
		places *= 10;
	}
	if (i < 0)
	{
		_putchar('-');
		count++;
	}
	while (places > 0)
	{
		dig = i / places;
		places /= 10;
		if (i <  0)
			_putchar(dig % 10 *  (-1) + '0');
		else
			_putchar(dig % 10 + '0');
		count++;
	}
	return (count);
}
