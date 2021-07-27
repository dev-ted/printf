#include "holberton.h"

/**
 * print_percentage - prints a percent
 * @list: arguments from _printf
 * @func: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_percentage(va_list list, param_func *func)
{
	(void)list;
	(void)func;
	_putchar('%');
	return (1);
}

/**
 * print_stringUpper - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @list: arguments from _printf
 * @func: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_stringUpper(va_list list, param_func *func)
{
	int i, count = 0;
	char *str;
	char *v_arg;

	v_arg = va_arg(list, char *);
	(void)func;
	if (!v_arg)
		return (_puts("(null)"));

	for (i = 0; v_arg[i]; i++)
	{
		if (v_arg[i] > 0 && (v_arg[i] < 32 || v_arg[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			str = convert_num(v_arg[i], 16, 0);
			if (!str[1])
				count += _putchar('0');
			count += _puts(str);
		}
		else
			count += _putchar(v_arg[i]);
	}
	return (count);
}

/**
  * print_rot13 - encodes a string into rot13.
  * @list: arguments supllied to the function
  * @func: pointer to the flag function
  * Return: size the output text
  */
int print_rot13(va_list list, param_func *func)
{
	int j, i, count = 0;
	char *r;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";

	r = va_arg(list, char *);
	(void)func;

	if (r == NULL)
		r = ("null");
	for (j = 0; r[j] != '\0'; j++)
	{
		for (i = 0; input[i] != '\0'; i++)
		{
			if (r[j] == input[i])
			{
				_putchar(output[i]);
				count++;
				break;
			}
		}
	}
	return (count);
}

/**
*print_reverse - prints a string in reverse
*@list: string to print
*@func: pointer to the flag function
*Return: number of chars printed
*/
int print_reverse(va_list list, param_func *func)
{
	int i, j = 0;

	char *st = va_arg(list, char *);
	(void)func;

	if (st == NULL)
		st = ("null");
	for (i = 0; st[i] != '\0'; i++)
	;
	for (i -= 1 ; i >= 0; i--)
	{
		_putchar(st[i]);
		j++;
	}
	return (j);
}

