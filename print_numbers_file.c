#include "main.h"
/**
 * d - Write a function that returns if the character is digit or not.
 * @character: The input.
 * Return: It will return (character >= '0' && character <= '9').
*/
int d(int character)
{
	return (character >= '0' && character <= '9');
}

/**
 * str_len - Write a function that returns the length.
 * @slen: The string.
 * Return: It will return (index).
*/
int str_len(char *slen)
{
	int index;

	index = 0;
	while (*slen++)
	{
		index++;
	}
	return (index);
}

/**
 * value - Write a function that prints the numbers.
 * @str: The string.
 * @the_parameters: The parameters.
 * Return: It will return (r_s(str, the_parameters))
 * or (l_s(str, the_parameters)).
*/
int value(char *str, p_t *the_parameters)
{
	unsigned int index = str_len(str);
	int negative = (!the_parameters->unsigned_n && *str == '-');

	if (!the_parameters->precision_specifier && *str == '0' && !str[1])
		str = "";
	if (negative)
	{
		str++;
		index--;
	}
	if (the_parameters->precision_specifier != UINT_MAX)
		while (index++ < the_parameters->precision_specifier)
			*--str = '0';
	if (negative)
		*--str = '-';
	if (!the_parameters->minus_character)
		return (r_s(str, the_parameters));
	else
		return (l_s(str, the_parameters));
}

/**
 * r_s - Write a function that prints the numbers (right-shift).
 * @str: The string.
 * @the_parameters: The parameters.
 * Return: It will return (m).
*/
int r_s(char *str, p_t *the_parameters)
{
	char padding = ' ';
	unsigned int index = str_len(str);
	unsigned int m = 0;
	unsigned int n1;
	unsigned int n2;

	if (the_parameters->0_character && !the_parameters->minus_character)
		padding = '0';
	n1 = n2 = (!the_parameters->unsigned_n && *str == '-');
	if (n1 && index < the_parameters->width_specifier && padding == '0' &&
			!the_parameters->minus_character)
		str++;
	else
		n1 = 0;
	if ((the_parameters->plus_character && !n2) ||
			(!the_parameters->plus_character && the_parameters->space_character && !n2))
		index++;
	if (n1 && padding == '0')
		m = m + _putchar('-');
	if (the_parameters->plus_character && !n2 && padding == '0' &&
			!the_parameters->unsigned_n)
		m = m + _putchar('+');
	else if (!the_parameters->plus_character && the_parameters->space_character &&
			!n2 && !the_parameters->unsigned_n && the_parameters->0_character)
		m = m + _putchar(' ');
	while (index++ < the_parameters->width_specifier)
		m = m + _putchar(padding);
	if (n1 && padding == ' ')
		m = m + _putchar('-');
	if (the_parameters->plus_character && !n2 && padding == ' ' &&
			!the_parameters->unsigned_n)
		m = m + _putchar('+');
	else if (!the_parameters->plus_character && the_parameters->space_character &&
			!n2 && !the_parameters->unsigned_n && !the_parameters->0_character)
		m = m + _putchar(' ');
	m = m + _puts(str);
	return (m);
}

/**
 * l_s - Write a function that prints the numbers (left-shift).
 * @str: The string.
 * @the_parameters: The parameters.
 * Return: It will return (m).
*/
int l_s(char *str, p_t *the_parameters)
{
	char padding = ' ';
	unsigned int index = str_len(str);
	unsigned int m = 0;
	unsigned int n1;
	unsigned int n2;

	if (the_parameters->0_character && !the_parameters->minus_character)
		padding = '0';
	n1 = n2 = (!the_parameters->unsigned_n && *str == '-');
	if (n1 && index < the_parameters->width_specifier && padding == '0' &&
			!the_parameters->minus_character)
		str++;
	else
		n1 = 0;
	if (the_parameters->plus_character && !n2 &&
			!the_parameters->unsigned_n)
		m = m + _putchar('+'), index++;
	else if (the_parameters->space_character && !n2 &&
			!the_parameters->unsigned_n)
		m = m + _putchar(' '), index++;
	m = m + _puts(str);
	while (index++ < the_parameters->width_specifier)
		m = m + _putchar(padding);
	return (m);
}
