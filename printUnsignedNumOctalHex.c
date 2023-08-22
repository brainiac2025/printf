#include "main.h"

/**
 * print_octal - function to print unsigned int
 * @argument: number to print
 * @flags: flag specifier
 * Return: void
 */
int print_octal(va_list argument, flag *flags)
{
	unsigned long num;
	char *string;
	int count = 0;

	if (flags->l_modifier)
	{
		num = (unsigned long)va_arg(argument, unsigned long);
	}
	else if (flags->h_modifier)
	{
		num = (unsigned short int)va_arg(argument, unsigned int);
	}
	else
	{
		num = (unsigned int)va_arg(argument, unsigned int);
	}

	string = to_base(num, 8, CHANGE_UNSIGNED, flags);

	if (flags->hash && num)
	{
		*--string = '0';
	}

	flags->unsign = 1;
	return (count += display_number(string, flags));
}

/**
 * print_unsigned_int - function to print octal number
 * @argument: decimal number
 * @flags: flag specifier
 * Return: void
 */
int print_unsigned_int(va_list argument, flag *flags)
{
	unsigned long num;

	if (flags->l_modifier)
		num = (unsigned long)va_arg(argument, unsigned long);
	else if (flags->h_modifier)
		num = (unsigned short int)va_arg(argument, unsigned int);
	else
		num = (unsigned int)va_arg(argument, unsigned int);
	flags->unsign = 1;
	return (display_number(to_base(num, 10, CHANGE_UNSIGNED, flags), flags));
}

/**
 * print_hex_lower - function to print hexadecimal in lowercase
 * @argument: decimal number entered
 * @flags: flag specifier
 * Return: void
 */
int print_hex_lower(va_list argument, flag *flags)
{
	unsigned long num;
	char *string;
	int count = 0;

	if (flags->l_modifier)
		num = (unsigned long)va_arg(argument, unsigned long);
	else if (flags->h_modifier)
		num = (unsigned short int)va_arg(argument, unsigned int);
	else
		num = (unsigned int)va_arg(argument, unsigned int);

	string = to_base(num, 16, CHANGE_UNSIGNED | CONVERT_HEX_CASE, flags);

	if (flags->hash && num)
	{
		*--string = 'x';
		*--string = '0';
	}
	flags->unsign = 1;
	return (count += display_number(string, flags));
}

/**
 * print_hex_upper - function to print hexadecimal in upper
 * @argument: decimal number entered
 * @flags: flag specifier
 * Return: void
 */
int print_hex_upper(va_list argument, flag *flags)
{
	char *string;
	int count = 0;
	unsigned int num;

	if (flags->l_modifier)
		num = (unsigned long)va_arg(argument, unsigned long);
	else if (flags->h_modifier)
		num = (unsigned short int)va_arg(argument, unsigned int);
	else
		num = (unsigned int)va_arg(argument, unsigned int);

	string = to_base(num, 16, CHANGE_UNSIGNED, flags);
	if (flags->hash && num)
	{
		*--string = 'X';
		*--string = '0';
	}
	flags->unsign = 1;
	return (count += display_number(string, flags));
}
