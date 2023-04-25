#include "main.h"
/**
 * length - Write a function that prints the length of the char address.
 * @s: The start point.
 * @e: The end point.
 * @ex: The except point.
 * Return: It will return (result).
*/
int length(char *s, char *e, char *ex)
{
	int result;

	result = 0;
	while (s <= e)
	{
		if (s != ex)
		{
			result = result + _putchar(*s);
		}
		s++;
	}
	return (result);
}
/**
 * reverse - Write a function that prints the reverse.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (result).
*/
int reverse(va_list ptr, p_t *the_parameters)
{
	int result;
	int length;
	char *s = va_arg(ptr, char *);
	(void)the_parameters;

	result = 0;
	if (s)
	{
		for (length = 0; *s; s++)
		{
			length++;
		}
		s--;
		for (; length > 0; length--, s--)
		{
			result = result + _putchar(*s);
		}
	}
	return (result);
}

/**
 * rot_13 - Write a function that prints the rot13.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (ct).
*/
int rot_13(va_list ptr, p_t *the_parameters)
{
	int ct;
	int n;
	int j;
	char Array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(ptr, char *);
	(void)the_parameters;

	j = 0;
	ct = 0;
	while (s[n])
	{
		if ((s[n] >= 'A' && s[n] <= 'Z')
				|| (s[n] >= 'a' && s[n] <= 'z'))
		{
			j = s[n] - 65;
			ct = ct + _putchar(Array[j]);
		}
		else
		{
			ct = ct + _putchar(s[n]);
		}
		n++;
	}
	return (ct);
}
