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
 * reverse_string - reverses a string in place
 *
 * @s: string to reverse
 * Return: A pointer to a character
 */
char *reverse_string(char *s)
{
	int len;
	int head;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
		dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	_memcpy(dest, s, len);
	for (head = 0; head < len; head++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}
