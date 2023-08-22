#include "main.h"

/**
 * print_character - function to print character
 * @argument: character to print
 * @flag: flag specifier
 * Return: void
 */
int print_character(va_list argument, flag *flag)
{
	char empty = ' ';
	unsigned int inc = 1;
	int count = 0;
	char ch = va_arg(argument, int);

	if (flag->minus)
		count += _putchar(ch);
	while (inc++ < flag->width)
		count += _putchar(empty);
	if (!flag->minus)
		count += _putchar(ch);

	return (count);
}

/**
 * print_string - function to print string
 * @argument: the string to be printed
 * @flag: flag specifier
 * Return: count
 */
int print_string(va_list argument, flag *flag)
{
	char inc_char = ' ';
	unsigned int index, count = 0;
	unsigned int i;
	unsigned int inc = 0;
	char *string = va_arg(argument, char*);
	(void)flag;

	if ((int) (!string))
		string = NULL_S;

	if (flag->precise < inc)
		index = inc = flag->precise;

	if (flag->minus)
	{
		if (flag->precise != UINT_MAX)
		{
			for (i = 0; i < inc; i++)
				count += _putchar(*string++);
		}
		else
		{
			count += display(string);
		}
	}
	while (index++ < flag->width)
		count += _putchar(inc_char);
	if (!flag->minus)
	{
		if (flag->precise != UINT_MAX)
		{
			for (i = 0; i < inc; i++)
				count += _putchar(*string++);
		}
		else
		{
			count += display(string);
		}
	}
	return (count);
}

/**
 * _isdigit - function to check if character is digit
 * @ch: character
 * Return: the cha
 */
int _isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * print_percent - function to print percent
 * @argument: va_list arg
 * @flag: flag specifier
 * Return: %
 */
int print_percent(va_list argument, flag *flag)
{
	(void)argument;
	(void)flag;
	return (_putchar('%'));
}
