#include "main.h"

/**
 * handlePositiveSign - is responsible for adding positive sign('+') or space
 * @count: the function update count as it adds positive signs
 * @flags: a pointer to a structure containing formatting flags
 * @len: pointer to an integer representing the current length of the
 * string being formatted
 * @neg2: An integer flag indicating whaether the number is negative
 * Return: 1 if a positive sign ('+') or 0 if no positive sign or space added
 */
int handlePositiveSign(unsigned int *count, flag *flags, unsigned int *len,
		int neg2)
{
	if (flags->plus && !neg2 && flags->unsign)
	{
		(*count) += _putchar('+');
		(*len)++;
		return (1); /* Sign handled, return early*/
	}
	else if (flags->space && !neg2 && !flags->unsign)
	{
		(*count) += _putchar(' ');
		(*len)++;
		return (1); /*Sign handled, return early*/
	}
	return (0); /*Sign not handled*/
}

/**
 * addPadding - the function is responsible for adding padding characters
 * either (0 or space) to a string in order to achive specify width
 * @count: the count of character so far
 * @flags: a pointer to a structure containing formatting flags that specify
 * the width and padding character
 * @len: a pointer representing current length of the string
 * @pad_char: representing a padding character to be added (either 0 or space)
 * Return: void
 */
void addPadding(unsigned int *count, flag *flags, unsigned int *len,
		char pad_char)
{
	while ((*len)++ < flags->width)
	{
		(*count) += _putchar(pad_char);
	}
}

/**
 * print_alignment - used for formatting and pointing a given string
 * @str: a pointer to a string that need to be printed
 * @flags: a pointer to a structure containing formattings flags
 * @isRightAlignment: an integer flag indicating whether the alignment is on
 * the right  if (set to 1 for right alignment 0 for left alignment)
 * Return: an integer representing the total number of characters printed
 */
int print_alignment(char *str, flag *flags, int isRightAlignment)
{
	unsigned int count = 0;
	char pad_char = ' ';
	int neg, neg2;
	unsigned int len = mylen(str);
	/*Determine the padding character*/
	if (flags->zero && !flags->minus)
		pad_char = '0';
    /*Check if it's a negative number*/
	neg = neg2 = (!flags->unsign && *str == '-');
    /*Remove '-' sign if necessary*/
	if (neg && len < flags->width && pad_char == '0' && !flags->minus)
		str++;
	else
		neg = 0;
	/* Handle '+' or ' ' for positive numbers*/
	if (handlePositiveSign(&count, flags, &len, neg2))
		return (count);

    /*Add padding on the right if right alignment is requested*/

	if (isRightAlignment)
	{
		addPadding(&count, flags, &len, pad_char);
	}
	/* print '-' sign if necessary*/
	if (neg && pad_char == ' ')
		count += _putchar('-');
	/* handle + for positive number (left alignmennt)*/
	handlePositiveSign(&count, flags, &len, neg2);

	/* add padding on the left if left alignment is requested*/
	if (!isRightAlignment)
	{
		addPadding(&count, flags, &len, pad_char);
	}
	/*print the actual number*/
	count += display(str);
	return (count);
}

/**
 * print_right_alignment - the function call print_alignment with specific
 * parameter
 * @str: a pointer to a string that needs to be printed
 * @flags: a pointer to a structure containing formatiing flags
 * Return: an integer representing the total number of characters printed
 */
int print_right_alignment(char *str, flag *flags)
{
	return (print_alignment(str, flags, 1));
}

/**
 * print_left_alignment - function that call print_alignment with specific
 * parameter
 * @str: a pointer to a string that needs to be printed
 * @flags: a pointer to a structure containing flags
 * Return: an integer representing the total number of characters printed
 */
int print_left_alignment(char *str, flag *flags)
{
	return (print_alignment(str, flags, 0));
}
