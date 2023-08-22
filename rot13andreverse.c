#include "main.h"

/**
 * reverse_string - function to reverse a string
 * @argument: - string to reverse
 * Return: void
 */
int reverse_string(va_list argument, flag *flag)
{
	char *string = va_arg(argument, char *);
	int length = mylen(string);
	int i, j;
	int count = 0;
	char *temp = malloc(length + 1);
	(void)flag;

	for (i = 0; i < length; i++)
	{
		temp[i] = string[length - i - 1];
	}
	temp[i] = '\0';
	for (j = 0; temp[j] != '\0'; j++)
	{
		count += _putchar(temp[j]);
	}

	free(temp);
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
		return(0);

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
