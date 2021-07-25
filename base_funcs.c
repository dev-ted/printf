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

int print_heX(va_list list)
{
    /*unsigned int hex_num = va_arg(list, unsigned int);
    char *heX_string = convert_func(hex_num, 16, 10);
    int count = 0;
    if (heX_string[0] != '0')
        count += _putchar("0X");
    count += _putchar(heX_string[0]);
    return count;*/

    unsigned int num;
    int len;
    int rem_num;
    char *hex_rep;
    char *rev_hex;

    num = va_arg(list, unsigned int);

    if (num == 0)
        return (_putchar('0'));
    if (num < 1)
        return (-1);
    len = get_base_len(num, 16);
    hex_rep = malloc(sizeof(char) * len + 1);
    if (hex_rep == NULL)
        return (-1);
    for (len = 0; num > 0; len++)
    {
        rem_num = num % 16;
        if (rem_num > 9)
        {
            rem_num = hex_check(rem_num, 'X');
            hex_rep[len] = rem_num;
        }
        else
            hex_rep[len] = rem_num + 48;
        num = num / 16;
    }
    hex_rep[len] = '\0';
    rev_hex = reverse_string(hex_rep);
    if (rev_hex == NULL)
        return (-1);
    get_write_base(rev_hex);
    free(hex_rep);
    free(rev_hex);
    return (len);
}

