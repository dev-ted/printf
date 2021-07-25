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
