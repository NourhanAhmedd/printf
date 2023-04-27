#include "main.h"
/**
 * _puts - Write a function that prints a strings.
 * @s: The string.
 * Return: It will return (s - p).
*/
int _puts(char *s)
{
	char *p = s;

	while (*s)
	{
		_putchar(*s++);
	}
	return (s - p);
}

/**
 * _putchar - Write a function that prints character as their names specifies.
 * @character: The input.
 * Return: 0 (Success) or -1 (Error).
*/
int _putchar(int character)
{
	static int index;
	static char b[LOCAL_BUFFER];

	if (character == BUFFER_F || index >= LOCAL_BUFFER)
	{
		write(1, b, index);
		index = 0;
	}

	if (character != BUFFER_F)
	{
		b[index++] = character;
	}
	return (1);
}
