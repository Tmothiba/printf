#include "main.h"

/************************* writing handles *************************/
/**
 * handle_write_char –Writes a character to a buffer.
 * @c: character to write.
 * @buffer: buffer array to handle the character
 * @flags: calculates active flags
 * @width: width
 * @precision: precision for formatting
 * @size: size of the buffer.
 *
 * Return: Number of characters written to buffer.
 */

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int a = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[a++] = c;
	buffer[a] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			buffer[BUFF_SIZE - a - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
				write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/************************* write number *************************/
/**
 * write_number - this prints a string
 * @is_negative: list of arguments
 * @ind: char types
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: Number of chars printed
 */

int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num – this function writes a number using a buffer
 * @ind: index at which the number starts on the buffer
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @prec: precision specifier
 * @length: number length
 * @padd: padding character
 * @extra_c: extra character
 *
 * Return: Number of printed chars
 */
int write_num(int ind, char buffer[], int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int a, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (a = 1; a < width - length + 1; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Assign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], a - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], a - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], a - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - this writes an unsigned number
 * @is_negative: number indicating if the num is negative
 * @ind: index at which the number starts in the buffer
 * @buffer: array of chars
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number of written chars
 */

int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the buffer's right and starts at position a */
	int length = BUFF_SIZE - ind - 1, a = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (a = 0; a < width - length; a++)
			buffer[a] = padd;

		buffer[a] = '\0';

		if (flags & F_MINUS) /* Assign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], a));
		}
		else /* Assign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], a) + write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer – this writes a memory address
 * @buffer: arrays of chars
 * @ind: index at which the number starts in the buffer
 * @length: length of number
 * @width: width
 * @flags: flags
 * @padd: char representing the padding
 * @extra_c: char representing extra char
 * @padd_start: index at which padding should start
 *
 * Return: number of written chars
 */

int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int a;

	if (width > length)
	{
		for (a = 3; a < width - length + 3; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], a - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], a - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], a - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}


