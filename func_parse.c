#include "holberton.h"

/**
 * func_parse - function that checks specifier and
 * and get the correct print function
 * @c: character with specifier
 * Description: the function loops through the structs array
 * f_list[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: the correct function
 */
int (*func_parse(char c))(va_list, param_func *)
{
	f_convert f_list[] = {
	    {'i', print_integer},
	    {'s', print_strings},
	    {'c', print_chars},
	    {'d', print_integer},
	    {'u', print_unsigned_integer},
	    {'x', print_hexa},
	    {'X', print_heX},
	    {'b', print_binary},
	    {'o', print_octal},
	    {'S', print_stringUpper},
	    {'%', print_percentage},
	    {'p', print_address},
	    {'R', print_rot13},
	    {NULL, NULL}
	};
	int args_flags = sizeof(f_list);

	register int i;

	for (i = 0; i < args_flags; i++)
		if (f_list[i].type == c)
		return (f_list[i].func);
	return (NULL);
}

/**
 *get_flags - finds the flag func
 *@s: the format string
 *@func: pointer to flag function
 * Return: if flag was valid
 */
int get_flags(char *s, param_func *func)
{
	int i = 0;

	switch (*s)
	{
	case '+':
		i = func->plus_flag = 1;
		break;
	case ' ':
		i = func->space_flag = 1;
		break;
	case '#':
		i = func->hash_flag = 1;
		break;
	case '0':
		i = func->zero_flag = 1;
		break;
	case '-':
		i = func->minus_flag = 1;
		break;
	
	}
	return (i);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @list: argument pointer
 * @func: the parameters struct
 *
 * Return: the number of bytes printed
 */
int print_func(char *s, va_list list, param_func *func)
{
	int (*f)(va_list, param_func *) = func_parse(s);
	if (f)
		return (f(list, func));
	return (0);
}
