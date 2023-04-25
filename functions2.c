#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_d - a function that prints decimal integers
 * @args: parameter
 * Return: int
 */
int print_d(va_list args)
{
	int num = va_arg(args, int);
	int digit_count = count_digits(num);
	int byte_sum = 0, i = 0;

	if (num < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		byte_sum++;
		num = -num;
	}
	if (num == 0)
	{
		write(STDOUT_FILENO, "0", 1);
		byte_sum++;
	}
	else
	{
		char *digits = malloc(digit_count * sizeof(char));

		if (digits == NULL)
		{
			return (-1);
		}
		i = digit_count - 1;
		while (num > 0)
		{
			digits[i] = (num % 10) + '0';
			num = num / 10;
			i--;
		}
		i = 0;
		while (i < digit_count)
		{
		write(STDOUT_FILENO, &digits[i], 1);
		byte_sum++;
		i++;
		}
		free(digits);
	}
	return (byte_sum);
}
/**
 * print_i - function that prints i
 *@arg: it is a parameter
 * Return: int
 */
int print_i(va_list arg)
{
return (print_d(arg));
}

/**
 * count_digits - function that prints i
 *@num: it is a parameter
 * Return: int
 */
int count_digits(int num)
{
	int count = 0;

	if (num == 0)
		return (1);
	if (num < 0)
	{
	count++;
	num = -num;
	}
	while (num > 0)
	{
	count++;
	num = num / 10;
	}
	return (count);
}
