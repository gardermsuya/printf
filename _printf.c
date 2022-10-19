#include "main.h"

/**
 * no_struct - a helper function that is called when theres a %something
 * @c: the character passed after the %
 * @count:the number of count thus far. it will be incremented
 * @argu: the va_list that is passsed to us so we can va_arg it
 *
 * Description:i did not use struct like everyone else
 * Return: the count totals
 *
 * A: we passed that character after the %. use it as switch condition
 * B:if it is a char, we put char + one count
 * C:if it is a string we check if null, if so then we put null plus 6
 *	we also put string if not null and count the stuff
 * D:if it is an i, do the same as d. so we put i and let it cascade down
 *	if the number is 0 then we add 1 to counts and put a zero
 *	else we just print the number
 * E:if it was a % then we just plus 1 and put the %
 * H:the default is to just print the %letter and yeah...
 *
 */
int no_struct(char c, int count, va_list argu)
{
	int j;
	char *s;

	switch (c) /*A*/
	{
		case 'c': /*B*/
			j = va_arg(argu, int);
			count += _putchar(j);
			break;
		case 's':
			s = va_arg(argu, char *);
			if (!s)
			{
				_putchar('(');
				_putchar('n');
				_putchar('u');
				_putchar('l');
				_putchar('l');
				_putchar(')');
				count += 6;
			}
			else
				count += _putstring(s);
			break;
		case '%': /*E*/
			count += _putchar('%');
			break;
		default: /*H*/
			count += 2;
			_putchar('%');
			_putchar(c);
	}
	return (count);
}

/**
 *_printf - our own printf function
 * @format : A character string, composed of zero of more directives
 *
 * Description: write a formated string to the standard output
 * Return: an integer the number of character printed excluding the null byte
 * A: if format is null then we return -1
 * B: as long as the format is not null we increment
 * C: if the index is not a % then we puts and count++
 * D: erase the deeeee
 * E: if it is not a null then we scan the letter. pass it into help func
 * F: it is probably a null so we return -1
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list argu;

	va_start(argu, format);

	if (!format)/* A */
		return (-1);

	for (i = 0; format[i]; i++)/* B */
	{
		if (format[i] != '%')/* C */
		{
			count++;
			_putchar(format[i]);
		}
	}
	va_end(argu);
	return (count);
}
