#include "main.h"

/**
 * oct_len - function to calculate octal len
 * @num: the number
 * Return: the len
 */
unsigned int oct_len(unsigned int num)
{
	unsigned int count;

	count = 0;

	if (num > 0)
		count = 1 + (oct_len(num / 8));
	else
		return (0);
	return (count);
}
/**
 * count_digit - function to count digit len of base 10
 * @num: chractert to count
 * Return: equivalent caracter
 */
unsigned int count_digit(unsigned int num)
{
	unsigned int count;

	count = 0;

	if (num > 0)
		count = 1 + (count_digit(num / 10));
	else
		return (0);
	return (count);
}


/**
 * print_integer - function to print Decimal number
 * @argument: number to print
 * @flag: flag specifier
 * Return: coutn
 */
int print_integer(va_list argument, flag *flag)
{
	int num = va_arg(argument, int);
	int n;
	int i;
	int j;
	int numdigit;
	char *mynum;
	int count = 0;
	(void)flag;

	if (num == 0)
	{
		_putchar('0');
	}

	if (num < 0)
	{
		_putchar('-');
		n = -num;
	}
	else
	{
		n = num;
	}

	numdigit = count_digit(n);
	mynum = malloc(sizeof(char) * numdigit);

	for (i = 0; i < numdigit; i++)
	{
		mynum[i] = (n % 10) + '0';
		n /= 10;
	}

	for (j = numdigit - 1; j >= 0; j--)
	{
		count += _putchar(mynum[j]);
	}
	free(mynum);
	return (count);
}

/**
 * find_width - function to that get width from the format string
 * @ch: the format
 * @argument: the va_list arg
 * @flag: the flag
 * Return: the string
 */
char *find_width(char *ch, va_list argument, flag *flag)
{
	int temp = 0;

	if (*ch == '*')
	{
		temp = va_arg(argument, int);
		ch++;
	}
	else
	{
		while (_isdigit(*ch))
			temp = temp * 10 + (*ch++ - '0');
	}
	flag->width = temp;
	return (ch);
}

/**
 * find_precise - function that get position from format string
 * @ch: the format string
 * @argument: the va_list arg
 * @flag: the flag format
 * Return: pointer to the function
 */
char *find_precise(char *ch, flag *flag, va_list argument)
{
	int precise = 0;

	if (*ch != '.')
		return (ch);

	ch++;

	if (*ch == '*')
	{
		precise = va_arg(argument, int);
		ch++;
	}
	else
	{
		while (_isdigit(*ch))
			precise = precise * 10 + (*ch++ - '0');
	}
	flag->precise = precise;
	return (ch);
}
