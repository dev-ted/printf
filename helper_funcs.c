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
 * convert_func - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * Return: result string
 */

char *convert_func(unsigned long int num, int base, int lowercase)
{
	char *array;
	char buffer[50];
	char *str_lowercase;
	char *str_uppercase;
	char *ptr;

	str_lowercase = "0123456789abcdef";
	str_uppercase = "0123456789ABCDEF";

	array = (lowercase)
				? str_lowercase
				: str_uppercase;
	ptr = &buffer[49];
	*ptr = '\0';
	do
	{
		*--ptr = array[num % base];
		num /= base;
} while (num != 0);
return (ptr);
}

/**
 * hex_check - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}