#include "holberton.h"

/**
 *_printf - Print a formatted string
 *@format: format string
 *Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int characters;
	f_convert f_list[] = {
		{"c", print_chars},
		{"s", print_strings},
		{"%", print_percentage},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", print_unsigned_integer},
		{"x", print_hexa},
		{"o", print_octal}
		{"X", print_heX},

	};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	characters = func_parse(format, f_list, args);
	va_end(args);
	return (characters);
}
