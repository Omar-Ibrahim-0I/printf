#include <stdarg.h>
#include <unistd.h>
#include <string.h>

void print_str(va_list arg)
{
	char *ptr = va_arg(arg, char *);
	size_t len_str = strlen(ptr);

	write(STDOUT_FILENO, ptr, len_str);
}
	
void print_char(va_list arg)
{
	char ptr = va_arg(arg, int);

	write(STDOUT_FILENO, &ptr, 1);

}

void print_percent(va_list arg)
{

}
