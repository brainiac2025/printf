#include "main.h"

/**
 * flag_init - clear the struct and reset
 * @flags: the parameter flag
 * @argument: the va_list argument
 * Return: void
 */
void flag_init(flag *flags, va_list argument)
{
	flags->unsign = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precise = UINT_MAX;
	flags->h_modifier = 0;
	flags->l_modifier = 0;

	(void)argument;
}

/**
 * print_range - function to print a range of char
 * @begin: the begining
 * @end: the end point
 * @skip: skip char
 * Return: printed byte
 */
int print_range(char *begin, char *end, char *skip)
{
	int mod = 0;

	while (begin <= end)
	{
		if (begin != skip)
			mod = mod + _putchar(*begin);
		begin++;
	}
	return (mod);
}
