#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_str - a function
 * @arg: param
 */
void print_str(va_list arg)
{
	char *ptr = va_arg(arg, char *);
	size_t len_str =  _strlen(ptr);

	write(STDOUT_FILENO, ptr, len_str);
}
/**
 * print_char - a function
 * @arg: param
 */
void print_char(va_list arg)
{
	char ptr = va_arg(arg, int);

	write(STDOUT_FILENO, &ptr, 1);

}

/**
 * print_percent - a function
 * @arg: param
 */
void print_percent(__attribute__((unused)) va_list arg)
{
	write(STDOUT_FILENO, "%%", 1);
}

/**
 * _strlen - a function
 * @str: param
 * Return: an int
 */
int _strlen(const char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
		i++;
	return (i);
}

