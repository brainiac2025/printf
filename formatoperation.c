#include "main.h"

/**
 * get_format - finds the format
 * @ch: the format string
 * Return: the number of bytes printed
 */
int (*get_format(char *ch)) (va_list argument, flag * flags)
{
	format_mapping format_map[] = {
		{"c", print_character},
		{"s", print_string},
		{"i", print_integer},
		{"d", print_integer},
		{"b", print_binary},
		{"u", print_unsigned_int},
		{"o", print_octal},
		{"x", print_hex_lower},
		{"X", print_hex_upper},
		{"%", print_percent},
		{"S", string_miss_char},
		{"p", print_address},
		{"R", rot13},
		{"r", reverse_string},
		{NULL, NULL}
	};

	int index = 0;

	while (format_map[index].format)
	{
		if (*ch == format_map[index].format[0])
			return (format_map[index].print_format);
		index++;
	}
	return (NULL);
}

/**
 * find_func_toprint - function that find the format function
 * @ch: the format string
 * @argument: the va_list argument
 * @flags: the flag
 * Return: the number of bytes printed
 */
int find_func_toprint(char *ch, va_list argument, flag *flags)
{
	int (*print_format)(va_list, flag *) = get_format(ch);

	if (print_format)
		return (print_format(argument, flags));
	return (0);
}

/**
 * find_flag - function to find the flag func
 * @ch: the format string
 * @flags: the flag specifier
 * Return: flag if found
 */
int find_flag(char *ch, flag *flags)
{
	int myflag = 0;

	if (*ch == '+')
	{
		myflag = flags->plus = 1;
	}
	else if (*ch == '#')
	{
		myflag = flags->hash = 1;
	}
	else if (*ch == ' ')
	{
		myflag = flags->space = 1;
	}
	else if (*ch == '-')
	{
		myflag = flags->minus = 1;
	}
	else if (*ch == '0')
	{
		myflag = flags->zero = 1;
	}
	return (myflag);
}

/**
 * find_modifier - function to
 * @ch: the format string
 * @flags: the flag struct
 * Return: modifier if found
 */
int find_modifier(char *ch, flag *flags)
{
	int mymodifier = 0;

	if (*ch == 'l')
		mymodifier = flags->l_modifier = 1;
	else if (*ch == 'h')
		mymodifier = flags->h_modifier = 1;
	return (mymodifier);
}
