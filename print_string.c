#include "holberton.h"

/**
 *print_chars - prints a char
 *@list: list of arguments
 *Return: number of characters printed.
 */
int print_chars(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 *print_strings - prints strings
 *@list: list of arguments
 *Return: number of characters printed
 */
int print_strings(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
