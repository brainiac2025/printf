#include "main.h"

/**
 * print_address - function to print address
 * @argument: pointer
 * @flags: flag specifier
 * Return: void
 */
int print_address(va_list argument, flag *flags)
{
	unsigned long int num = va_arg(argument, unsigned long int);
	char *string;

	if (!num)
	{
		return (display("(nil)"));
	}
	string = to_base(num, 16, CHANGE_UNSIGNED | CONVERT_HEX_CASE, flags);
	*--string = 'X';
	*--string = '0';
	return (display_number(string, flags));
}
