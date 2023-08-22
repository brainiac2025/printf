#include "main.h"

/**
 * display - function that write to screen
 * @string: character to print
 * Return: equivalent int in memory
 */
int display(char *string)
{
	char *newch = string;

	while (*string)
	{
		_putchar(*string++);
	}
	return (string - newch);
}

/**
 * mylen - function to get length of string
 * @string: the string
 * Return: the length of it
 */
int mylen(char *string)
{
	int index = 0;

	while (string[index] != '\0')
	{
		index++;
	}
	return (index);
}

/**
 * _putchar - function to writes character to stdout
 * @chr: the character
 * Return:1 on success
 */
int _putchar(int chr)
{
	static int inc;
	static char buffer[BUFF_SIZE];

	if (chr == FLUSH_BUFF || inc >= BUFF_SIZE)
	{
		write(1, buffer, inc);
		inc = 0;
	}
	if (chr != FLUSH_BUFF)
		buffer[inc++] = chr;
	return (1);
}
