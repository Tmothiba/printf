#include "main.h"

/************************* print char *************************/

/**
 * print_char - this prints a char
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);
	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/************************* print a string *************************/
/**
 * print_string - this prints a string
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */

int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int length = 0, a;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
	{
		length = precision;
	}
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (a = width - length; a > 0; a--)
			{
				write(1, " ", 1);
			}
			return (width);
		}
		else
		{
			for (a = width - length; a > 0; a--)
			{
				write(1, " ", 1);
			}
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
/************************* print percent sign *************************/
/**
 * print_percent - this prints percent sign
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */

int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* print int *************************/
/**
 * print_int - this prints int
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */

int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2, is_negative = 0;
	long int r = va_arg(types, long int);
	unsigned long int num;

	r = convert_size_number(r, size);
	if (r == 0)
	{
		buffer[a--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)r;

	if (r < 0)
	{
		num = (unsigned long int)((-1) * r);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}
	a++;

	return (write_number(is_negative, a, buffer, flags, width, precision, size));
}

/************************* print binary *************************/
/**
 * print_binary - this prints an unsigned number
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: numbers of char printed
 */

int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int j, c, i, sum, a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(types, unsigned int);
	c = 2147483648; 
	a[0] = j / c;
	for (i = 1; i < 32; i++)
	{
		c /= 2;
		a[i] = (j / c) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char x = '0' + a[i];

			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

