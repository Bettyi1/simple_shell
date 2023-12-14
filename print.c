#include "shell.h"
/**
 * _shellp - print function
 * @string: funtion description
 * Return: Always 0
 */
void _shellp(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
