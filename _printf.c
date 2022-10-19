#include "main.h"

int no_struct(char c, int count, va_list argu)
{
	int j;
	char *s;

	switch (c) /*A*/
	{
		case 'c':
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
		default:
			count += 2;
			_putchar('%');
			_putchar(c);		
	}
	return (count);
}
