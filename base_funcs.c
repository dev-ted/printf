#include "holberton.h"

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

/**
 * hexa_length - return the lenght of a number converted in hexa
 * @n: the number
 * Return: the length
 */

int hexa_length(unsigned int n)
{
	int count = 0;

	while (n > 0)
	{
		if (n <= 16)
		{
			count++;
			break;
		}
		count++;
		n /= 16;
	}
	return (count);
}

/**
 * hexa - return abcdef if number is > 10
 * @n: number
 * Return: the char
 */

char hexa(int n)
{
	switch (n)
	{
		case 10:
			return ('a');
		case 11:
			return ('b');
		case 12:
			return ('c');
		case 13:
			return ('d');
		case 14:
			return ('e');
		case 15:
		return ('f');
	}
	return ('N');
}

/**
 * print_hexa - print an hexadecimal number
 * @args: the number passed
 * Return: the length of number printed
 */

int print_hexa(va_list list)
{
	int i = 0, length = 0, res = 0, j = 0;
	unsigned int n = 0;
	char *string;

	n = va_arg(list, unsigned int);
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	length = hexa_length(n);
	string = malloc((length * sizeof(char)) + 1);
	if (string == NULL)
		return (-1);
	i = length - 1;
	while (n > 0)
	{
		if (n <= 16)
		{
			if (n < 10)
				string[i] = n + 48;
			else
				string[i] = hexa(n);
			break;
		}
		res = n % 16;
		if (res >= 10)
			string[i] = hexa(res);
		else
			string[i] = res + 48;
		n /= 16;
		i--;
	}
	for (j = 0; j < length; j++)
		_putchar(string[j]);
	free(string);
	return (length);
}
/**
 * octal_length - return the length of a number convert to octal
 * @n: the number
 * Return: the length
 */

int octal_length(unsigned int n)
{
	int count = 0;

	while (n > 0)
	{
		if (n <= 8)
		{
			count++;
			break;
		}
		n /= 8;
		count++;
	}
	return (count);
}

/**
 * print_octal - print a number converted in octal
 * @args: the argument received
 * Return: the length of printed in console
 */

int print_octal(va_list list)
{
	int i = 0, length = 0, res = 0, j = 0;
	unsigned int n = 0;
	char *string;

	n = va_arg(list, unsigned int);
	length = octal_length(n);
	string = malloc(length * sizeof(char) + 1);
	i = length - 1;
	while (n > 0)
	{
		if (n <= 8)
		{
			string[i] = n + 48;
			break;
		}
		res = n % 8;
		string[i] = res + 48;
		n /= 8;
		i--;

	}
	for (j = 0; j < length; j++)
		_putchar(string[j]);
	free(string);
	return (length);
}


