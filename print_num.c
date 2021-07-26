#include "holberton.h"

/**
 * print_integer - print an integer
 * @list: list of arguments
 * @func: flags for the print function
 * Return: the length of printed in console
 */
int print_integer(va_list list, param_func *func)
{
	int i;
	int num_of_digits;

	i =  va_arg(list, int);
	num_of_digits = get_digits(i);
	/* check for flags */
	if (func->space_flag == 1 && func->plus_flag == 0 && i >= 0)
		num_of_digits += _putchar(' ');
	if (func->plus_flag == 1 && i >= 0)
		num_of_digits += _putchar('+');
	if (i <= 0)
		num_of_digits++;/* increment*/
	/* print the number */
	print_num(i);
	return (num_of_digits);
}

/**
*print_unsigned_integer - print an unsigned integer
*@list: list of arguments
*@func: flags for the print function
*Return: the length of printed in console
*/
int print_unsigned_integer(va_list list, param_func *func)
{
	unsigned int unsigned_num;
	char *str;

	unsigned_num = va_arg(list, unsigned int);
	str = convert_num(unsigned_num, 10, 0);
	(void)func;
	return (_puts(str));
}
