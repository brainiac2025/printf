#include "main.h"

/**
 * reverse_string - function to reverse a string
 * @argument: - string to reverse
 * Return: void
 */
void reverse_string(va_list argument)
{
	char *string = va_arg(argument, char *);
	int length = mylen(string);
	int i, j;
	char *temp = malloc(length + 1);

	for (i = 0; i < length; i++)
	{
		temp[i] = string[length - i - 1];
	}
	temp[i] = '\0';
	for (j = 0; temp[j] != '\0'; j++)
	{
		display(temp[j]);
	}

	free(temp);
}

/**
 * rot13 - function that print rot13'ed string
 * @argument:  the string
 * Return: void
 */
void rot13(va_list argument)
{
	char *string = va_arg(argument, char *);
	int index, index2, i;
	char condition[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char replacement[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *myrot = malloc(mylen(string) + 1);

	if (myrot == NULL)
		return;

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
		display(myrot[i]);
	}
	free(myrot);
}
