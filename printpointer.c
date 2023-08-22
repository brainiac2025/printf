#include "main.h"

/**
 * reverse - function to reverse hex
 * @str: character to pointer
 * Return: void
 */
void reverse(char *str)
{
	int length = mylen(str);
	char temp;
	int i;

	for (i  = 0; i < length / 2; i++)
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}
}
/**
 * address_to_hex - function to convert address to hexadecimal
 * @ptr: the address to convert
 * @hexstring: the hexstring
 * Return: void
 */
void address_to_hex(void *ptr, char *hexstring)
{
	int index, i;
	const char hex_char[] = "0123456789abcdef";
	unsigned long address = (unsigned long)ptr;

	int hexlen = sizeof(void *) * 2;

	for (i = hexlen - 1; i >= 0; i--)
	{
		index = (address % 10);
		hexstring[hexlen - 1 - i] = hex_char[index];
		address /= 16;
	}
	hexstring[hexlen] = '\0';
}

/**
 * print_address - function to print address
 * @argument: pointer
 * @flag: flag specifier
 * Return: void
 */
int print_address(va_list argument, flag *flag)
{
	void *ptr = va_arg(argument, void *);
	char myadr[sizeof(void *) * 2 + 1];
	int index;
	int count = 0;
	(void)flag;

	address_to_hex(ptr, myadr);
	reverse(myadr);

	for (index = 0; myadr[index] != '\0'; index++)
	{
		count += _putchar(myadr[index]);
	}
	return (count);
}
