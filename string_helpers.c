#include "holberton.h"

/**
 * reverse_string - reverses a string in place
 *
 * @s: string to reverse
 * Return: A pointer to a character
 */
char *reverse_string(char *s)
{
	int len, head;
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

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * init_params - clears struct fields and reset buf
 * @func: the parameters struct
 * @list: the argument pointer
 *
 * Return: void
 */
void init_params(param_func *func, va_list list)
{
	func->unsign = 0;

	func->plus_flag = 0;
	func->space_flag = 0;
	func->hash_flag = 0;
	func->zero_flag = 0;
	func->minus_flag = 0;

	func->width = 0;
	func->precision = UINT_MAX;

	func->h_mod = 0;
	func->l_mod = 0;
	(void)list;
}