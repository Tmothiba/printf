#include "main.h"
<<<<<<< HEAD

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format
 * Return: Printed chars
 */

int _printf(const char *format, ...)
{
	int a, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[i] != '\0'; i++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[a], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &a);
			width = get_width(format, &a, list);
			precision = get_precision(format, &a, list);
			size = get_size(format, &a);
			++a;
			printed = handle_print(format, &a, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - prints the contents of the buffer available
 * @buffer: array of chars
 * @buff_ind: index at which to add next char, represents the length
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

=======
/**
 * _printf - function that prints formats
 * @format: format.
 * Return: Printed chars.
 */
void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{

	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
        va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
                return (-1);

	}

	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}
			printed_chars++;
                }
		else
		{
		print_buffer(buffer, &buff_ind);
		flags = get_flags(format, &i);
		width = get_width(format, &i, args);
		precision = get_precision(format, &i, args);
		size = get_size(format, &i);
		++i;

		printed = handle_print(format, &i, args, buffer, flags, width, precision, size);

		if (printed == -1)
		{
			return (-1);
		}
		printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);
	return (printed_chars);
}


/**
 * print_buffer - this function prints contents of the buffers.
 * @buffer: Array of characters.
 * @buff_ind: pointer to an int Index that represents the length. of the buffer
 */

void print_buffer(char buffer[], int *buff_ind)

{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}
>>>>>>> printf
