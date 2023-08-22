#include "main.h"

/**
 * string_miss_char - function to escape some character
 * @argument: the string
 * @flags: flag specifier
 * Return: void
 */
int string_miss_char(va_list argument, flag *flags)
{
	char *str = va_arg(argument, char*);
	char *hex;
	int count = 0;

	if ((int)(!str))
		return (display(NULL_S));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			hex = to_base(*str, 16, 0, flags);

			if (!hex[1])
				count += _putchar('0');
			count += display(hex);
		}
		else
		{
			count += _putchar(*str);
		}
	}
	return (count);
}
