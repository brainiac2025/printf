#include "main.h"

/**
 * char_to_hex - function to convert character to Hex
 * @c: the char
 * @hex: the hexadecimal
 * Return: void
 */
void char_to_hex(char c, char *hex)
{
	const char  *myHex = "0123456789ABCDEF";
	int high_nibble, low_nibble;

	high_nibble = (c / 16) % 16;
	low_nibble = (c % 16);

	hex[0] = myHex[high_nibble];
	hex[1] = myHex[low_nibble];
	hex[2] = '\0';
}

/**
 * string_miss_char - function to escape some character
 * @argument: the string
 * Return: void
 */
void string_miss_char(va_list argument)
{
	char *str = va_arg(argument, char*);
	int index, ascivalue;
	int i;
	char sub[4];

	for (index = 0; str[index] != '\0'; index++)
	{
		ascivalue = (int)str[index];

		if ((ascivalue < 32) || (ascivalue > 127))
		{
			sub[0] = '\\';
			sub[1] = 'x';
			char_to_hex(str[index], sub + 2);

			for (i = 0; i < 4; i++)
			{
				display(sub[i]);
			}
			index++;
		}

		display(str[index]);
	}
}
