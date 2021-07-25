#include "holberton.h"

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
 * print_num - prints a number send to this function
 * @list: List of arguments
 * Return: The number of arguments printed
 */
int print_num(va_list list)
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

/**
 * unsigned_number - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int unsigned_number(unsigned int n)
{
	int i, length;
	unsigned int num;

	i = 1;
	length = 0;
	num = n;
	for (; num / i > 9;)
		i *= 10;
	for (; i != 0;)
	{
		length += _putchar('0' + (num / i));
		num %= i;
		i /= 10;
	}
	return (length);
}

/*
* print_unsigned_integer - print an unsigned integer
*@list: list of arguments
*Return: the length of printed in console
*/
int print_unsigned_integer(va_list list)
{
	unsigned int unsigned_num;

	unsigned_num = va_arg(list, unsigned int);
	if (unsigned_num == 0)
		return (unsigned_number(unsigned_num));
	if (unsigned_num < 1)
		return (-1);
	return (unsigned_number(unsigned_num));
}
