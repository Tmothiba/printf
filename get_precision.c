#include "main.h"
/**
 * get_precision - this function calculates the precision for printing formats
 * @format: pointer to a formatted string.
 * @i: lists of arguments
 * @list: list of arguments
 * Return: int
 */
int get_precision(const char *format, int *i, va_list list)
{
	int cur = *i + 1, precision = -1;

	if (format[cur] != '.')
	{
		return (precision);
	}
	precision = 0;
	for (cur = 1; format[cur] != '\0'; cur++)
	{
		if (is_digit(format[cur]))
		{
			precision *= 10;
			precision += format[cur] - '0';
		}
		else if (format[cur] == '*')
		{
			cur++;
			precision = va_arg(list, int);
			break;
		}
		else
		{
		break;
		}
	}
	*i = cur - 1;
	return (precision);
}




