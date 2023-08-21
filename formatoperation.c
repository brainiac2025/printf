#include "main.h"

format_mapping *get_format_map()
{
	static format_mapping format_map[] = {
		{'c', print_character},
		{'s', print_string},
		{'i', print_integer},
		{'d', print_integer},
		{'b', print_binary},
		{'u', print_unsigned_int},
		{'o', print_octal},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'S', string_miss_char},
		{'p', print_address},
		{'R', rot13},
		{'r', reverse_string},
		{0, NULL}
	};
	return (format_map);
}
