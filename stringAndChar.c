#include "main.h"

/**
 * print_character - function to print character
 * @argument: character to print
 * @flag: flag specifier
 * Return: void
 */
int print_character(va_list argument, flag *flag)
{
	char ch = va_arg(argument, int);
	(void)flag;

	return (_putchar(ch));
}

/**
 * print_string - function to print string
 * @argument: the string to be printed
 * @flag: flag specifier
 * Return: count
 */
int print_string(va_list argument, flag *flag)
{
	int index = 0;
	int count = 0;
	char *string = va_arg(argument, char*);
	(void)flag;

	while (string[index] != '\0')
	{
		count += _putchar(string[index]);
		index++;
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
