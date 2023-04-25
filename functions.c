#include <stdarg.h>
#include <unistd.h>
#include "main.h"
void print_str(va_list arg)
{
	char *ptr = va_arg(arg, char *);
	size_t len_str =  _strlen(ptr);

	write(STDOUT_FILENO, ptr, len_str);
}
	
void print_char(va_list arg)
{
	char ptr = va_arg(arg, int);

	write(STDOUT_FILENO, &ptr, 1);

}

void print_percent(__attribute__((unused)) va_list arg)
{
	write(STDOUT_FILENO, "%%", 1);
}

int _strlen(const char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
		i++;
	return (i);
}

