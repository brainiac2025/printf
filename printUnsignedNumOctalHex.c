#include "main.h"

/**
 * count_hex_digit - function to count hex digit
 * @num: the number pass
 * Return: int
 */
unsigned int count_hex_digit(unsigned int num)
{
	unsigned int count = 0;

	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}
/**
 * print_octal - function to print unsigned int
 * @argument: number to print
 * Return: void
 */
void print_octal(va_list argument)
{
	unsigned int num = va_arg(argument, unsigned int);
	int i;
	int j;
	unsigned int octlen = oct_len(num);
	char *myoct;

	if (num == 0)
	{
		display('0');
		return;
	}
	myoct = malloc(sizeof(char) * octlen);
	i = 0;

	while (num > 0)
	{
		myoct[i] = (num % 8) + '0';
		num /= 8;
		i++;
	}

	for (j = octlen - 1; j >= 0; j--)
	{
		display(myoct[j]);
	}
	free(myoct);
}

/**
 * print_unsigned_int - function to print octal number
 * @argument: decimal number
 * Return: void
 */
void print_unsigned_int(va_list argument)
{
	unsigned int num = va_arg(argument, unsigned int);
	unsigned int i;
	unsigned int numdigit;
	int j;
	char *mynum;

	if (num == 0)
		display('0');

	numdigit = count_digit(num);
	mynum = malloc(sizeof(char) * numdigit);

	for (i = 0; i < numdigit; i++)
	{
		mynum[i] = (num % 10) + '0';
		num /= 10;
	}

	for (j = numdigit - 1; j >= 0; j--)
	{
		display(mynum[j]);
	}
	free(mynum);
}

/**
 * print_hex_lower - function to print hexadecimal in lowercase
 * @argument: decimal number entered
 * Return: void
 */
void print_hex_lower(va_list argument)
{
	unsigned int num = va_arg(argument, unsigned int);
	unsigned int i, base, remain;
	unsigned int digitlen = count_hex_digit(num);
	char *myhex = malloc(sizeof(char) * (digitlen + 1));

	if (myhex == NULL)
		return;

	base = 16;

	for (i = digitlen; num > 0; i--)
	{
		remain = num % base;

		if (remain < 10)
			myhex[i] = (remain + '0');
		else
			myhex[i] = ((remain - 10 + 'a'));
		num /= base;
	}
	for (i = 0; i <= digitlen; i++)
	{
		display(myhex[i]);
	}
	free(myhex);
}

/**
 * print_hex_upper - function to print hexadecimal in upper
 * @argument: decimal number entered
 * Return: void
 */
void print_hex_upper(va_list argument)
{
	unsigned int num = va_arg(argument, unsigned int);
	unsigned int i, base, remain;
	unsigned int digitlen = count_hex_digit(num);
	char *myhex = malloc(sizeof(char) * (digitlen + 1));

	if (myhex == NULL)
		return;

	base = 16;

	for (i = digitlen; num > 0; i--)
	{
		remain = num % base;

		if (remain < 10)
			myhex[i] = (remain + '0');
		else
			myhex[i] = ((remain - 10 + 'A'));
		num /= base;
	}

	for (i = 0; i <= digitlen; i++)
	{
		display(myhex[i]);
	}
	free(myhex);
}
