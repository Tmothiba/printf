#include "main.h"

/**
 * get_size - function that calculates the size to cast the arguments
 * @format: pointer to a string
 * @i: list of arguments
 * Return: int
 */
int get_size(const char *format, int *i)
{
	int cur = *i + 1, size = 0;

	if (format[cur] == '|')
	{
	size = S_LONG;
	}
	else if (format[cur] == 'h')
	{
		size = S_SHORT;
	}

	if (size == 0)
	{
		*i = cur - 1;
	}
	else
	{
		*i = cur;
	}
	return (size);
}

