#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFF_SIZE 1024
#define FLUSH_BUFF -1

#define NULL_S "(null)"

#define FLAG_OFF {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
/**
 * struct parameters - parameters struct
 * @plus: on if +
 * @space: on if ' '
 * @hash: on if #
 * @zero: on if 0
 * @minus: on if -
 *
 * @width: field width specifier
 * @precise: field precision specifield
 *
 * @h_modifier: on if h is specify
 * @l_modifier: on if l is specifier
 */
typedef struct parameters
{
	unsigned int unsign	: 1;

	unsigned int plus	: 1;
	unsigned int space	: 1;
	unsigned int hash	: 1;
	unsigned int zero	: 1;
	unsigned int minus	: 1;

	unsigned int width;
	unsigned int precise;

	unsigned int h_modifier	: 1;
	unsigned int l_modifier	: 1;
} flag;


/**
 * struct format - token specifier
 * @format: format input
 * @print_format: function aaociated
 */
typedef struct format
{
	char *format;
	int (*print_format)(va_list, flag *);
} format_mapping;

int _printf(const char *format, ...);

int mylen(char *string);

int display(char ch);

void print_integer(va_list argument, flag *flag);

unsigned int power(unsigned int num, unsigned int p);

unsigned int count_digit(unsigned int num);

void print_unsigned_int(va_list argument, flag *flag);

void print_octal(va_list argument, flag *flag);

void print_hex_lower(va_list argument, flag *flag);

void print_hex_upper(va_list argument, flag *flag);

void print_binary(va_list argument, flag *flag);

void print_string(va_list argument, flag *flag);

void string_miss_char(va_list flag flag *flag);

void print_character(va_list argument, flag *flag);

void char_to_hex(char c, char *hex);

void print_address(va_list argument, flag *flag);

void address_to_hex(void *ptr, char *hexstring);

void numberToString(unsigned int num, char *string);

void reverse_string(va_list argument, flag *flag);

void rot13(va_list argument, flag *flag);

unsigned int binarylen(unsigned int num);

unsigned int count_hex_digit(unsigned int num);

unsigned int oct_len(unsigned int num);

void reverse(char *str);

format_mapping *get_format_map();

char *precise(char *ptr, va_list argument);

void flag_init(flag *flag, va_list argument);

#endif
