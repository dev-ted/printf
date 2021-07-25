#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct func_convert - gets structure for the symbols and functions
*@type: operator symbols
*@func: the associated function
*/

struct func_convert
{
    char *type;
    int (*func)(va_list);
};
typedef struct func_convert f_convert;

/*function prototypes*/
int _printf(const char *format, ...);
int func_parse(const char *format, f_convert func_list[], va_list args);
int _putchar(char c);
int print_chars(va_list);
int print_strings(va_list);
int print_percentage(va_list);
int print_integer(va_list);
int print_binary(va_list list);
int print_unsigned_integer(va_list list);

/* Utils */
int print_num(va_list);
unsigned int get_base_len(unsigned int num, unsigned int base);
void get_write_base(char *str);
char *reverse_string(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
int unsigned_number(unsigned int n);

#endif