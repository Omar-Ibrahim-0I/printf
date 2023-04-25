#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - printf clone
 * @format: character
 *
 * Return: 0 if success
 */
int _printf(const char *format, ...)
{
	va_list args;
	fr formates[] = {
		{'c', &print_char},
		{'s', &print_str},
	};
	int i = 0, j = 0, len = strlen(format);
	
	va_start(args, format);
	while (i < len)
	{
		if (format[i] == '%')
		{
			while (j < 3)
			{
				if (formates[j].c == format[i + 1])
					formates[j].f(args);
				j++;
			}
		}
		else if (format[i -1] == '%')
		{
		}
		else
		{
			write(STDOUT_FILENO, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return 1;
}
