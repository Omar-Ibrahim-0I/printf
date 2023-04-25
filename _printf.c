#include <stdarg.h>
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
		{'%', &print_percent}
	};
	int i = 0, j = 0, len = _strlen(format);

	va_start(args, format);
	while (i < len)
	{
		if (format[i] == '%')
		{
			while (j < 3)
			{
				if (formates[j].c == format[i + 1])
				{
					formates[j].f(args);
					i++;
					break;
				}
				j++;
			}
			if (j >= 3)
				write(STDOUT_FILENO, &format[i], 1);
			j = 0;
		}
		else
		{
			write(STDOUT_FILENO, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (0);
}
