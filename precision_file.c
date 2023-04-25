#include "main.h"
/**
 * prec - Write a function that prints the precision.
 * @pr: The string.
 * @the_parameters: The parameters.
 * @ptr: The pointer.
 * Return: It will return (pr).
*/
char *prec(char *pr, p_t *the_parameters, va_list ptr)
{
	int n;

	n = 0;
	if (*pr != '.')
	{
		return (pr);
	}
	pr++;
	if (*pr == '*')
	{
		n = va_arg(ptr, int);
		pr++;
	}
	else
	{
		while (d(*pr))
		{
			n = n * 10 + (*pr++ - '0');
		}
	}
	the_parameters->precision_specifier = n;
	return (pr);
}
