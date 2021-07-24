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
 * @args: the argument received
 * Return: the length of printed in console
 */

int print_integer(va_list list)
{
	long int num = 0, div = 1, count = 0;

	num = va_arg(list, int);

	if (num >= 0 && num <= 9)
	{
	_putchar('0' + num);
		return (1);
	}
	else if (num < 0)
	{
		_putchar('-');
		num = -num;
		count = 1;
	}
	if (num > 0)
	{
		while (div <= num)
			div *= 10;
		while (div > 1)
		{
			div /= 10;
			_putchar((num / div) + '0');
			num %= div;
			count++;
		}
	}
	return (count);
}

