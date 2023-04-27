#ifndef PRINTF_H
#define PRINTF_H
/* The libraries: */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
/* Some requirements: */
#define LOWERCASE_C 1
#define UNSIGNED_C 2
#define LOCAL_BUFFER 1024
#define BUFFER_F -1
#define N_STR "(null)"
#define PARAMETERS_VALUE {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/* The first struct:  */
/**
 * struct p_v - struct p_v.
 * @unsigned_n: The unsigned numbers.
 * @width_specifier: The field width for non-custom conversion specifiers.
 * @precision_specifier: The precision for non-custom conversion specifiers.
 * @plus_character: The (+) flag for non-custom conversion specifiers.
 * @space_character: The ( ) flag for non-custom conversion specifiers.
 * @hash_character: The (#) flag for non-custom conversion specifiers.
 * @l_length_modifier: The first length modifier.
 * @h_length_modifier: The second length modifier.
 * @z_character: The (0) flag character for non-custom conversion specifiers.
 * @minus_character: The (-) flag for non-custom conversion specifiers.
*/
typedef struct p_v
{
	unsigned int unsigned_n         : 1;
	unsigned int width_specifier;
	unsigned int precision_specifier;
	unsigned int plus_character     : 1;
	unsigned int space_character    : 1;
	unsigned int hash_character     : 1;

	unsigned int l_length_modifier  : 1;
	unsigned int h_length_modifier  : 1;

	unsigned int z_character        : 1;
	unsigned int minus_character    : 1;
} p_t;

/* The second struct:  */
/**
 * struct s_token - Specifier token.
 * @s_token: The format.
 * @f: The function that we will use.
*/
typedef struct s_token
{
	char *s_token;
	int (*f)(va_list, p_t *);
} s_t;

/* The functions: */
int (*the_specifier(char *s))(va_list ptr, p_t *the_parameters);
char *the_field_width(char *s, p_t *the_parameters, va_list ptr);
int function(char *s, va_list ptr, p_t *the_parameters);
int the_modifier(char *s, p_t *the_parameters);
int flag_character(char *s, p_t *the_parameters);

int _putchar(int character);
int _puts(char *s);

int integer_function(va_list ptr, p_t *the_parameters);
int string_function(va_list ptr, p_t *the_parameters);
int char_function(va_list ptr, p_t *the_parameters);
int percent_function(va_list ptr, p_t *the_parameters);
int S_function(va_list ptr, p_t *the_parameters);

int unsigned_numbers(va_list ptr, p_t *the_parameters);
int add(va_list ptr, p_t *the_parameters);
char *c(long int value, int b, int f, p_t *the_parameters);

int length(char *s, char *e, char *ex);
int reverse(va_list ptr, p_t *the_parameters);
int rot_13(va_list ptr, p_t *the_parameters);

int convert_to_HEX(va_list ptr, p_t *the_parameters);
int convert_to_hex(va_list ptr, p_t *the_parameters);
int convert_to_oct(va_list ptr, p_t *the_parameters);
int convert_to_binary(va_list ptr, p_t *the_parameters);

int d(int character);
int str_len(char *slen);
int value(char *str, p_t *the_parameters);
int r_s(char *str, p_t *the_parameters);
int l_s(char *str, p_t *the_parameters);

int _printf(const char *format, ...);
char *prec(char *pr, p_t *the_parameters, va_list ptr);
void parameter_function(p_t *the_parameters, va_list ptr);

#endif /* PRINTF_H */
