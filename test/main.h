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
	void (*f)(va_list);
} fr;

void print_str(va_list arg);
void print_char(va_list arg);
void print_percent(va_list arg);
#endif /* main_h  */
