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
int print_d(va_list arg);
int print_i(va_list arg);
int count_digits(int num);
int print_b(va_list arg);
int count_bits(int number);
#endif /* main_h  */
