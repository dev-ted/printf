#include "holberton.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int print;
	char *name;
	

	name = "  is fun";
	print = _printf("%c%s%i%d%b\n", 'c', name, 3, 7,0);
	printf("%d\n", print);
	return (0);
}

