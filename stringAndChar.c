#include "main.h"

/**
 * print_character - function to print character
 * @argument: character to print
 * Return: void
 */
void print_character(va_list argument)
{
	char ch = va_arg(argument, int);

	display(ch);
}

/**
 * print_string - function to print string
 * @argument: the string to be printed
 * Return: void
 */
void print_string(va_list argument)
{
	int index = 0;
	char *string = va_arg(argument, char*);

	while (string[index] != '\0')
	{
		display(string[index]);
		index++;
	}
}
