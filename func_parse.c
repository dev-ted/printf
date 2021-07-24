#include "holberton.h"

/**
 * func_parse - function that gets main string and parameters
 * and returns a formated string
 * @format: string with specified characters
 * @func_list: list of functions
 * @args: list of arguments
 * Return: number of characters printed
 */
int func_parse(const char *format, f_convert func_list[], va_list args)
{
	int i, j, f_value, characters;

	characters = 0;
	/* check each character in the main string */
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')/* checks coversion specifies*/
		/* go through the list of functions to find the right function */
		for (j = 0; func_list[j].type != NULL; j++)
		{
			if (format[i + 1] == func_list[j].type[0])
			{
				f_value = func_list[j].func(args);
				if (f_value == -1)
					return (-1);
				characters += f_value;
				break;
			}
		}
		/* if function not found*/
		if (func_list[j].type == NULL && format[i + 1] != ' ')
		{
			if (format[i + 1] != '\0')/* if not the end of the string */
			{
				_putchar(format[i]);/* print the character */
				_putchar(format[i + 1]);/* print and incriment i */
				characters += 2;
			}
			else
			{
				return (-1);
			}
			i += 1;/* skip format characters */
		}
		else
		{
			/* call _putchar and print the characters */
			_putchar(format[i]);
			characters++;
		}
	}
	return (characters);
}
