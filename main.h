#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct format
{
	char format;
	void (*print_format)(va_list);
} format_mapping;

int _printf(const char *format, ...);

int mylen(char *string);

int display(char ch);

void print_integer(va_list argument);

unsigned int power(unsigned int num, unsigned int p);

unsigned int count_digit(unsigned int num);

void print_unsigned_int(va_list argument);

void print_octal(va_list argument);

void print_hex_lower(va_list argument);

void print_hex_upper(va_list argument);

void print_binary(va_list argument);

void print_string(va_list argument);

void string_miss_char(va_list argument);

void print_character(va_list argument);

void char_to_hex(char c, char *hex);

void print_address(va_list argument);

void address_to_hex(void *ptr, char *hexstring);

void numberToString(unsigned int num, char *string);

void reverse_string(va_list argument);

void rot13(va_list argument);

unsigned int binarylen(unsigned int num);

unsigned int count_hex_digit(unsigned int num);

unsigned int oct_len(unsigned int num);

void reverse(char *str);

format_mapping *get_format_map();

#endif
