#include "main.h"

/**
 * get_flags - this calculates active flags
 * @format: formatted string in which to print the arguments
 * @i: take a parameter
 * Return: Flags:
 */

int get_flags(const char *format, int *i)
{
<<<<<<< HEAD
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
=======
>>>>>>> printf
	int a, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[curr_i] == FLAGS_CH[a])
			{
<<<<<<< HEAD
				flags |= FLAGS_ARR[a];
=======
				flags = FLAGS_ARR[a];
>>>>>>> printf
				break;
			}
		if (FLAGS_CH[a] == 0)
			break;
	}
	*i = curr_i - 1;
	return (flags);
}

