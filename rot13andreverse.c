#include "main.h"

/**
 * reverse_string - function to reverse a string
 * @argument: - string to reverse
 * @flags: the flag specify
 * Return: void
 */
int reverse_string(va_list argument, flag *flags)
{
	char *string = va_arg(argument, char *);
	int length;
	int count = 0;
	(void)flags;

	if (string)
	{
		for (length = 0; *string; string++)
		{
			length++;
		}
		string--;

		for (; length > 0; length--, string--)
		{
			count += _putchar(*string);
		}
	}
	return (count);
}

/**
 * rot13 - function that print rot13'ed string
 * @argument:  the string
 * @flag: flag specifier
 * Return: void
 */
int rot13(va_list argument, flag *flag)
{
	char *string = va_arg(argument, char *);
	int index, index2, i;
	int count = 0;
	char condition[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char replacement[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *myrot = malloc(mylen(string) + 1);
	(void)flag;

	if (myrot == NULL)
		return (0);

	index = 0;
	while (string[index] != '\0')
	{
		index2 = 0;
		while (condition[index2] != '\0')
		{
			if (string[index] == condition[index2])
			{
				myrot[index] = replacement[index2];
				break;
			}
			else
			{
				myrot[index] = string[index];
			}
			index2++;
		}

		index++;
	}

	myrot[index] = '\0';
	for (i = 0; myrot[i] != '\0'; i++)
	{
		count += _putchar(myrot[i]);
	}
	free(myrot);
	return (count);
}
