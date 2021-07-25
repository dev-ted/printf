#include "holberton.h"
#include <stdio.h>
#include <limits.h>

/**
 * main - Entry point(TEST FILE TO BE DELETED)
 *
 * Return: Always 0
 */
int main(void)
{

	char *name;
	double d =  -290909;
	unsigned int ui;

	name = " C is fun";
	ui = (unsigned int)INT_MAX + 1024;
	/*print = _printf("%c%s%i%d%b\n", 'c', name, 3, 7,0);*/
	/*printf("%d\n", print);*/
	_printf("char: %c\n", 'C');
	_printf("string: %s\n", name);
	_printf("Integer: %i\n", 3);
	_printf("Integer: %d\n", d);
	_printf("Binary number: %b\n", 1);
	/* printf("%u\n", ui);*/
	_printf("Unassigned num: %u\n", ui);
<<<<<<< HEAD
	_printf("Octal number:%o\n", 32);
	_printf("Hexa number:%x", 10);
=======
<<<<<<< Updated upstream
	_printf("Unsigned hexadecimal: %X\n", ui);
=======
<<<<<<< HEAD
	_printf("Octal number:%o\n", 32);
	_printf("Hexa number:%x", 10);
=======
	_printf("Unsigned hexadecimal: %X\n", ui);
>>>>>>> print_heX
>>>>>>> Stashed changes
>>>>>>> print_heX

	return (0);
}
