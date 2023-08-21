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
 * Return: void
 */
void print_binary(va_list argument)
{
	unsigned int n = va_arg(argument, unsigned int);
	unsigned int i, j;
	unsigned int *mybinary = malloc(sizeof(unsigned int) * binarylen(n));

	if (n == 0)
	{
		display('0');
		return;
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
		display(mybinary[j] + '0');
	}
	free(mybinary);
}
