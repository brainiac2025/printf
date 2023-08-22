#include "main.h"

/**
 * binarylen - function to calculate binarysize
 * @num: the number to check the size in binary
 * Return: the len
 */
unsigned int binarylen(unsigned int num)
{
	unsigned int count = 0;

	while (num != 0)
	{
		count++;
		num /= 2;
	}
	return (count);
}

/**
 * print_binary - function to printbinary
 * @argument: decimal number pass
 * @flag: flag specifier
 * Return: void
 */
int print_binary(va_list argument, flag *flag)
{
	unsigned int n = va_arg(argument, unsigned int);
	unsigned int i, j;
	int count = 0;
	unsigned int *mybinary = malloc(sizeof(unsigned int) * binarylen(n));
	(void)flag;

	if (n == 0)
	{
		display('0');
		return (0);
	}

	i = 0;
	while (n > 0)
	{
		mybinary[i] = n % 2;
		n /= 2;
		i++;
	}

	for (j = i - 1; j > 0; j--)
	{
		count += _putchar(mybinary[j] + '0');
	}
	free(mybinary);
	return (count);
}
