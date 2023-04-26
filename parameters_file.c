#include "main.h"
/**
 * parameter_function - Write a function that clears the structure.
 * @the_parameters: The parameters.
 * @ptr: The pointer.
*/
void parameter_function(p_t *the_parameters, va_list ptr)
{
	the_parameters->unsigned_n = 0;
	the_parameters->width_specifier = 0;
	the_parameters->precision_specifier = UINT_MAX;
	the_parameters->plus_character = 0;
	the_parameters->space_character = 0;
	the_parameters->hash_character = 0;

	the_parameters->l_length_modifier = 0;
	the_parameters->h_length_modifier = 0;

	the_parameters->0_character = 0;
	the_parameters->minus_character = 0;
	(void)ptr;
}
