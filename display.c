#include "main.h"

/**
 * display - function that write to screen
 * @ch: character to print
 * Return: equivalent int in memory
 */
int display(char ch)
{
	return (write(1, &ch, 1));
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
