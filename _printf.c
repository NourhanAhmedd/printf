#include "main.h"
/**
 * _printf - Write a function that produces output according to a format.
 * @format: The character string.
 * Return: It will return (result).
*/
int _printf(const char *format, ...)
{
	int result = 0;
	va_list ptr;
	char *s;
	char *p1;
	p_t parameters = PARAMETERS_VALUE;

	va_start(ptr, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p1 = (char *)format; *p1; p1++)
	{
		parameter_function(&parameters, ptr);
		if (*p1 != '%')
		{
			result = result + _putchar(*p1);
			continue;
		}
		s = p1;
		p1++;

		while (flag_character(p1, &parameters))
			p1++;
		p1 = the_field_width(p1, &parameters, ptr);
		p1 = prec(p1, &parameters, ptr);
		if (the_modifier(p1, &parameters))
			p1++;
		if (!the_specifier(p1))
		{
			result = result + length(s, p1, parameters.l_length_modifier ||
					parameters.h_length_modifier ? p1 - 1 : 0);
		}
		else
			result = result + function(p1, ptr, &parameters);
	}
	_putchar(BUFFER_F);
	va_end(ptr);
	return (result);
}
