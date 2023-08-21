#include "main.h"

/**
 * octlen - function to calculate octal len
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
 * Return: void
 */
void print_integer(va_list argument)
{
	int num = va_arg(argument, int);
	int n;
	int i;
	int j;
	int numdigit;
	char *mynum;

	if (num == 0)
	{
		display('0');
	}

	if (num < 0)
	{
		display('-');
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
		display(mynum[j]);
	}
	free(mynum);
}
