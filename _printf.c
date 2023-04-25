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
		{'c', &print_char}, {'s', &print_str}, {'%', &print_percent},
		{'d', &print_d}, {'i', &print_i}, {'b', &print_b}
	};
	int i = 0, j = 0, len = _strlen(format), byte_sum = 0;

	va_start(args, format);
	if (!format)
		return (-1);
	while (i < len)
	{
		if (format[i] == '%')
		{
			while (j < 6)
			{
				if (formates[j].c == format[i + 1])
				{
					byte_sum += formates[j].f(args);
					i++;
					break;
				}
				j++;
			}
			if (j >= 6)
			{
				write(STDOUT_FILENO, &format[i], 1);
				byte_sum++;
			}
			j = 0;
		}
		else
		{
			write(STDOUT_FILENO, &format[i], 1);
			byte_sum++;
		}
		i++;
	}
	va_end(args);
	return (byte_sum);
}
