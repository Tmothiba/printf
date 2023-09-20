#include "main.h"
/**
 * is_printable- checks is a character is printable
 * @c: character to be evaluated
 * Return: 1 if c is printable, 0 if its not.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}
/**
 * append_hexa_code - appends the ascii in hex code to buffer
 * @buffer: an array of characters
 * @i: index at which to start appending to the buffer
 * @ascii_code: ascii code
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - verifies if a char is a digit
 * @c: character to be checked
 * Return: 1 if c is a digit, or else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * convert_size_number - casts a number to the specified size
 * @num: the number to be casted
 * @size: size to be casted
 * Return: value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}
	return ((int)num);
}
/**
 * convert_size_unsgnd - this function casts a number to the size specified
 * @num: the number to be casted
 * @size: indicates the type to be casted
 * Return: value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}

