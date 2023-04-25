#include "main.h"
/**
 * convert_to_hex - Write a function that prints hex numbers (lowercase).
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (i = i + value(s, the_parameters)).
*/
int convert_to_hex(va_list ptr, p_t *the_parameters)
{
	unsigned long n;
	char *s;
	int i;

	i = 0;
	if (the_parameters->l_length_modifier)
	{
		n = (unsigned long)va_arg(ptr, unsigned long);
	}
	else if (the_parameters->h_length_modifier)
	{
		n = (unsigned short int)va_arg(ptr, unsigned int);
	}
	else
	{
		n = (unsigned int)va_arg(ptr, unsigned int);
	}
	s = c(1, 16, UNSIGNED_C | LOWERCASE_C, the_parameters);
	if (the_parameters->hash_character && n)
	{
		*--s = 'x';
		*--s = '0';
	}
	the_parameters->unsigned_numbers = 1;
	return (i = i + value(s, the_parameters));
}

/**
 * convert_to_HEX - Write a function that prints hex numbers (uppercase).
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (i = i + value(s, the_parameters)).
*/
int convert_to_HEX(va_list ptr, p_t *the_parameters)
{
	unsigned long n;
	char *s;
	int i;

	i = 0;
	if (the_parameters->l_length_modifier)
	{
		n = (unsigned long)va_arg(ptr, unsigned long);
	}
	else if (the_parameters->h_length_modifier)
	{
		n = (unsigned short int)va_arg(ptr, unsigned int);
	}
	else
	{
		n = (unsigned int)va_arg(ptr, unsigned int);
	}
	s = c(1, 16, UNSIGNED_C, the_parameters);
	if (the_parameters->hash_character && n)
	{
		*--s = 'x';
		*--s = '0';
	}
	the_parameters->unsigned_numbers = 1;
	return (i = i + value(s, the_parameters));
}

/**
 * convert_to_binary - Write a function that prints binary numbers.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (i = i + value(s, the_parameters)).
*/
int convert_to_binary(va_list ptr, p_t *the_parameters)
{
	int i;
	unsigned int m = va_arg(ptr, unsigned int);
	char *s = c(m, 2, UNSIGNED_C, the_parameters);

	i = 0;
	if (the_parameters->hash_character && m)
	{
		*--s = '0';
	}
	the_parameters->unsigned_numbers = 1;
	return (i = i + value(s, the_parameters));
}

/**
 * convert_to_oct - Write a function that prints octal numbers.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (i = i + value(s, the_parameters)).
*/
int convert_to_oct(va_list ptr, p_t *the_parameters)
{
	unsigned long n;
	char *s;
	int i;

	i = 0;
	if (the_parameters->l_length_modifier)
	{
		n = (unsigned long)va_arg(ptr, unsigned long);
	}
	else if (the_parameters->h_length_modifier)
	{
		n = (unsigned short int)va_arg(ptr, unsigned int);
	}
	else
	{
		n = (unsigned int)va_arg(ptr, unsigned int);
	}
	s = c(1, 8, UNSIGNED_C, the_parameters);
	if (the_parameters->hash_character && n)
	{
		*--s = '0';
	}
	the_parameters->unsigned_numbers = 1;
	return (i = i + value(s, the_parameters));
}
