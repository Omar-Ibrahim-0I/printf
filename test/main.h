#ifndef main_h
#define main_h
#include <stdarg.h>

int _printf(const char *format, ...);

/**
 * struct format - printf function format
 * @c: char
 * @f: function associated
 */
typedef struct format
{
	char c;
	int (*f)(va_list);
} fr;

int print_str(va_list arg);
int print_char(va_list arg);
int print_percent(va_list arg);
int _strlen(const char *str);
#endif /* main_h  */
