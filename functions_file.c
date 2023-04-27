#include "main.h"
/**
 * char_function - Write a function that prints char.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (result).
*/
int char_function(va_list ptr, p_t *the_parameters)
{
	unsigned int result;
	unsigned int padding;
	unsigned int c = va_arg(ptr, int);
	char padding_c = ' ';

	result = 0;
	padding = 1;
	if (the_parameters->minus_character)
	{
		result = result + _putchar(c);
	}
	while (padding++ < the_parameters->width_specifier)
	{
		result = result + _putchar(padding_c);
	}
	if (!the_parameters->minus_character)
	{
		result = result + _putchar(c);
	}
	return (result);
}

/**
 * integer_function - Write a function that prints integers.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (value(c(1, 10, 0, the_parameters),
 * the_parameters)).
*/
int integer_function(va_list ptr, p_t *the_parameters)
{
	long n;

	if (the_parameters->l_length_modifier)
	{
		n = va_arg(ptr, long);
	}
	else if (the_parameters->h_length_modifier)
	{
		n = (short int)va_arg(ptr, int);
	}
	else
	{
		n = (int)va_arg(ptr, int);
	}
	return (value(c(1, 10, 0, the_parameters), the_parameters));
}

/**
 * string_function - Write a function that prints string.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (result).
*/
int string_function(va_list ptr, p_t *the_parameters)
{
	unsigned int result = 0;
	unsigned int padding = 0;
	unsigned int index1 = 0;
	unsigned int index2;
	char *s = va_arg(ptr, char *);
	char padding_c = ' ';

	(void)the_parameters;
	switch ((int)(!s))
		case 1:
		s = N_STR;

	index2 = padding = str_len(s);
	if (the_parameters->precision_specifier < padding)
		index2 = padding = the_parameters->precision_specifier;
	if (the_parameters->minus_character)
	{
		if (the_parameters->precision_specifier != UINT_MAX)
			for (index1 = 0; index1 < padding; index1++)
				result = result + _putchar(*s++);
		else
			result = result + _puts(s);
	}
	while (index2++ < the_parameters->width_specifier)
		result = result + _putchar(padding_c);
	if (!the_parameters->minus_character)
	{
		if (the_parameters->precision_specifier != UINT_MAX)
			for (index1 = 0; index1 < padding; index1++)
				result = result + _putchar(*s++);
		else
			result = result + _puts(s);
	}
	return (result);
}

/**
 * percent_function - Write a function that prints the percent.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (result).
*/
int percent_function(va_list ptr, p_t *the_parameters)
{
	(void)ptr;
	(void)the_parameters;

	return (_putchar('%'));
}

/**
 * S_function - Write a function that prints the
 * custom conversion specifier.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (result).
*/
int S_function(va_list ptr, p_t *the_parameters)
{
	int result;
	char *s = va_arg(ptr, char *);
	char *h;

	result = 0;
	if ((int)(!s))
		return (_puts(N_STR));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			result = result + _putchar('\\');
			result = result + _putchar('x');
			h = c(*s, 16, 0, the_parameters);
			if (!h[1])
			{
				result = result + _putchar('0');
			}
			result = result + _puts(h);
		}
		else
		{
			result = result + _putchar(*s);
		}
	}
	return (result);
}
