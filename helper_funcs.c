#include "holberton.h"

/**
 * _memcpy - copy memory area
 * @dest: Destination for copying
 * @src: Source to copy from
 * @n: The number of bytes to copy
 * Return: The _memcpy() function returns a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}


/**
* get_base_len - Calculates the length for an octal number
 * @num: The number for which the length is being calculated
 * @base: Base to be calculated by
 * Return: An integer representing the length of a number
 */
unsigned int get_base_len(unsigned int num, unsigned int base)
{
	unsigned int len;

	for (len = 0; num > 0; len++)
	{
		num /= base;
	}
	return (len);
}

/**
 * get_write_base - sends characters to be written on standard output
 * @str: String to parse
 */
void get_write_base(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * get_mods - finds the modifier func
 * @str: the format string
 * @func: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_mods(char *str, param_func *func)
{
	int i = 0;

	switch (*str)
	{
		case 'h':
			i = func->h_mod = 1;
			break;
		case 'l':
			i = func->l_mod = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @str: the format string
 * @func: the parameters struct
 * @list: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *str, param_func *func, va_list list)
{
	int i = 0;

	if (*str == '*')
	{
		i = va_arg(list, int);
		i++;
	}
	else
	{
		while (is_digit(*str))
			i = i * 10 + (*str++ - '0');
	
	}
	func->width = i;
	return (i);
}

/**
 * get_precision - gets the precision from the format string
 * @str: the format string
 * @func: the parameters struct
 * @list: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *str, param_func *func, va_list list)
{
	int i = 0;

	if (*str != '*')
		return (str);
	str++;
	if (*str == '*')
	{
		i = va_arg(list, int);
		str++;
	}
	else
	{
		while (is_digit(*str))
			i = i * 10 + (*str++ - '0');

	}
	func->precision = i;
	return (str);
}
