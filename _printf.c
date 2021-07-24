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


	};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	characters = func_parse(format, f_list, args);
	va_end(args);
	return (characters);
}
