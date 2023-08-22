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
 * @flags: flag specifier
 * Return: void
 */
int print_octal(va_list argument, flag *flags)
{
	unsigned long num;
	char *string;
	int count = 0;

	if (flags->l_modifier)
	{
		num = (unsigned long)va_arg(argument, unsigned long);
	}
	else if (flags->h_modifier)
	{
		num = (unsigned short int)va_arg(argument, unsigned int);
	}
	else
	{
		num = (unsigned int)va_arg(argument, unsigned int);
	}

	string = to_base(num, 8, CHANGE_UNSIGNED, flags);

	if (flags->hash && num)
	{
		*--string = '0';
	}

	flags->unsign = 1;
	return (count += display_number(string, flags));
}

/**
 * print_unsigned_int - function to print octal number
 * @argument: decimal number
 * @flags: flag specifier
 * Return: void
 */
int print_unsigned_int(va_list argument, flag *flags)
{
	unsigned long num;

	if (flags->l_modifier)
		num = (unsigned long)va_arg(argument, unsigned long);
	else if (flags->h_modifier)
		num = (unsigned short int)va_arg(argument, unsigned int);
	else
		num = (unsigned int)va_arg(argument, unsigned int);
	flags->unsign = 1;
	return (display_number(to_base(num, 10, CHANGE_UNSIGNED, flags), flags));
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
