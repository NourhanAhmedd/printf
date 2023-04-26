#include "main.h"
/**
 * c - Write a function that prints the convert function.
 * @value: The integer number.
 * @b: The base.
 * @f: The flag.
 * @the_parameters: The parameters.
 * Return: It will return (pointer).
*/
char *c(long int value, int b, int f, p_t *the_parameters)
{
	char si;
	char *pointer;
	static char *a;
	static char buff[50];
	unsigned long number = value;
	(void)the_parameters;

	si = 0;
	if (!(f & UNSIGNED_C) && value < 0)
	{
		number = -value;
		si = '-';
	}

	a = f & LOWERCASE_C ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &buff[49];
	*pointer = '\0';

	do {
		*--pointer = a[number % b];
		number = number / b;
	} while (number != 0);

	if (si)
	{
		*--pointer = si;
	}
	return (pointer);
}

/**
 * unsigned_numbers - Write a function that prints the unsigned numbers.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (value(c(1, 10, UNSIGNED_C, the_parameters),
 * the_parameters)).
*/
int unsigned_numbers(va_list ptr, p_t *the_parameters)
{
	unsigned long n;

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
	the_parameters->unsigned_n = 1;
	return (value(c(1, 10, UNSIGNED_C, the_parameters), the_parameters));
}

/**
 * add - Write a function that prints the address.
 * @ptr: The pointer.
 * @the_parameters: The parameters.
 * Return: It will return (value(s, the_parameters)).
*/
int add(va_list ptr, p_t *the_parameters)
{
	char *s;
	unsigned long int a = va_arg(ptr, unsigned long int);

	if (!a)
	{
		return (_puts("(nil)"));
	}

	s = c(a, 16, UNSIGNED_C | LOWERCASE_C, the_parameters);
	*--s = 'x';
	*--s = '0';
	return (value(s, the_parameters));
}
