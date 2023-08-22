#include "main.h"

/**
 * to_base - function to convert to different base
 * base 2 for binary, base 10 for decimal, base 8 for octal
 * base 16 for hexadecimal
 * @num: number to convert
 * @base: base of the number
 * @sign_unsign: for sign or unsign number
 * @flags: struct flag
 * Return: string
 */
char *to_base(long int num, int base, int sign_unsign, flag *flags)
{
	char sign = 0;
	char *ptr;
	unsigned long mynum = num;
	static char holder[50];
	static char *hex_and_num_hold;
	(void)flags;

	if (!(sign_unsign & CHANGE_UNSIGNED) && num < 0)
	{
		mynum = -num;
		sign = '-';
	}

	if (sign_unsign & CONVERT_HEX_CASE)
		hex_and_num_hold = "0123456789abcdef";
	else
		hex_and_num_hold = "0123456789ABCDEF";

	ptr = &holder[49];
	*ptr = '\0';

	while (mynum != 0)
	{
		*--ptr = hex_and_num_hold[mynum % base];
		mynum /= base;
	}

	/* add the sign iif it's negative*/
	if (sign)
	{
		*--ptr = sign;
	}
	return (ptr);
}

/**
 * display_number - function to print number base on flag set
 * @str: the number pass as pointer
 * @flags: the flags set to it
 * Return: the print alignment
 */
int display_number(char *str, flag *flags)
{
	/* finding the length of the string str*/
	unsigned int i = mylen(str);
	/* check if the number is negative*/
	int neg = (!flags->unsign && *str == '-');
	/* if the number is not precise and is 0, set the string to zero*/
	if (!flags->precise && *str == '0' && !str[1])
		str = "";
/* check if number number is negative*/
	if (neg)
	{
		str++;
		i--;
	}
/* if precision is specified (not UNIT_MAX) add leading*/
/* zero until length matches precision*/
	if (flags->precise != UINT_MAX)
	{
		while (i++ < flags->precise)
			*--str = '0';
	}
	/* if the number is negative add - sign at the begining*/
	if (neg)
		*--str = '-';
	/* if minus flag is not set, print the number with right alignment*/
	if (!flags->minus)
		return (print_right_alignment(str, flags));
	else
		return (print_left_alignment(str, flags));
}
