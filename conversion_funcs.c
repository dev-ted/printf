#include "holberton.h"
#include <stdio.h>

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

/**
 * print_percentage - Prints a percent symbol
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_percentage(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * print_integer - print an integer
 * @list: list of arguments
 * Return: the length of printed in console
 */
int print_integer(va_list list)
{
	int i;

	i = print_num(list);
	return (i);
}

/**
 * print_binary - Converts a number from base 10 to binary
 * @list: List of arguments passed to this function
 * Return: The length of the number printed
 */
int print_binary(va_list list)
{
	unsigned int binary_num;
	int i, length;
	char *str;
	char *rev_string;

	binary_num = va_arg(list, unsigned int);
	if (binary_num == 0)
		return (_putchar('0'));
	if (binary_num < 1)
		return (-1);
	length = get_base_len(binary_num, 2);
	str = malloc(sizeof(char) * length + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; binary_num > 0; i++)
	{
		if (binary_num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		binary_num /= 2;
	}
	str[i] = '\0';
	rev_string = reverse_string(str);
	if (rev_string == NULL)
		return (-1);
	get_write_base(rev_string);
	free(str);
	free(rev_string);
	return (length);
}
