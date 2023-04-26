#include "main.h"
/**
 * the_specifier - Write a function that returns the format.
 * @s: The string.
 * Return: It will return (specifier_format) or (NULL).
*/
int (*the_specifier(char *s))(va_list ptr, p_t *the_parameters)
{
	s_t specifier_format[] = {
		{"c", char_function},
		{"d", integer_function},
		{"i", integer_function},
		{"s", string_function},
		{"%", percent_function},
		{"b", convert_to_binary},
		{"o", convert_to_oct},
		{"u", unsigned_numbers},
		{"x", convert_to_hex},
		{"X", convert_to_HEX},
		{"p", add},
		{"S", S_function},
		{"r", reverse},
		{"R", rot_13},
		{NULL, NULL}
	};
	int index = 0;

	while (specifier_format[index].s_token)
	{
		if (*s == specifier_format[index].s_token[0])
		{
			return (specifier_format[index].f);
		}
		index++;
	}
	return (NULL);
}

/**
 * function - Write a function that prints the function.
 * @s: The string.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: 0 (Success).
*/
int function(char *s, va_list ptr, p_t *the_parameters)
{
	int (*f)(va_list, p_t *) = the_specifier(s);

	if (f)
	{
		return (f(ptr, the_parameters));
	}
	return (0);
}

/**
 * flag_character - Write a function that prints the flag function.
 * @s: The string.
 * @the_parameters: The parameters.
 * Return: It will return (index).
*/
int flag_character(char *s, p_t *the_parameters)
{
	int index;

	index = 0;
	switch (*s)
	{
		case '+':
			index = the_parameters->plus_character = 1;
			break;
		case ' ':
			index = the_parameters->space_character = 1;
			break;
		case '#':
			index = the_parameters->hash_character = 1;
			break;
		case '0':
			index = the_parameters->z_character = 1;
			break;
		case '-':
			index = the_parameters->minus_character = 1;
			break;
	}
	return (index);
}

/**
 * the_modifier - Write a function that prints the modifier function.
 * @s: The string.
 * @the_parameters: The parameters.
 * Return: It will return (index).
*/
int the_modifier(char *s, p_t *the_parameters)
{
	int index;

	index = 0;
	switch (*s)
	{
		case 'l':
			index = the_parameters->l_length_modifier = 1;
			break;
		case 'h':
			index = the_parameters->h_length_modifier = 1;
			break;
	}
	return (index);
}

/**
 * the_field_width - Write a function that prints the width function.
 * @s: The string.
 * @the_parameters: The parameters.
 * @ptr: The pointer.
 * Return: It will return (s).
*/
char *the_field_width(char *s, p_t *the_parameters, va_list ptr)
{
	int w;

	w = 0;
	if (*s == '*')
	{
		w = va_arg(ptr, int);
		s++;
	}
	else
	{
		while (d(*s))
		{
			w = w * 10 + (*s++ - '0');
		}
	}
	the_parameters->width_specifier = w;
	return (s);
}
