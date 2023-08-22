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
 * @flag: flag specifier
 * Return: void
 */
int print_octal(va_list argument, flag *flag)
{
	unsigned int num = va_arg(argument, unsigned int);
	int i;
	int j;
	unsigned int octlen = oct_len(num);
	char *myoct;
	int count = 0;
	(void)flag;

	if (num == 0)
	{
		count += _putchar('0');
		return (0);
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
		count += _putchar(myoct[j]);
	}
	free(myoct);
	return (count);
}

/**
 * print_unsigned_int - function to print octal number
 * @argument: decimal number
 * @flag: flag specifier
 * Return: void
 */
int print_unsigned_int(va_list argument, flag *flag)
{
	unsigned int num = va_arg(argument, unsigned int);
	unsigned int i;
	unsigned int numdigit;
	int j;
	char *mynum;
	int count = 0;
	(void)flag;

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
		count += _putchar(mynum[j]);
	}
	free(mynum);
	return (count);
}

/**
 * print_hex_lower - function to print hexadecimal in lowercase
 * @argument: decimal number entered
 * @flag: flag specifier
 * Return: void
 */
int print_hex_lower(va_list argument, flag *flag)
{
	unsigned int num = va_arg(argument, unsigned int);
	unsigned int i, base, remain;
	unsigned int digitlen = count_hex_digit(num);
	char *myhex = malloc(sizeof(char) * (digitlen + 1));
	int count = 0;
	(void)flag;

	if (myhex == NULL)
		return (0);

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
		count += _putchar(myhex[i]);
	}
	free(myhex);
	return (count);
}

/**
 * print_hex_upper - function to print hexadecimal in upper
 * @argument: decimal number entered
 * @flag: flag specifier
 * Return: void
 */
int print_hex_upper(va_list argument, flag *flag)
{
	unsigned int num = va_arg(argument, unsigned int);
	unsigned int i, base, remain;
	unsigned int digitlen = count_hex_digit(num);
	char *myhex = malloc(sizeof(char) * (digitlen + 1));
	int count = 0;
	(void)flag;

	if (myhex == NULL)
		return (0);

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
		count += _putchar(myhex[i]);
	}
	free(myhex);
	return (count);
}
