#include <stdlib.h>
#include "kkshell.h"

/**
 * move_left - Removes leading zeros from a binary string.
 * @a: Buffer containing the binary string.
 * @size: Size of the buffer.
 * @num: Number of digits in the binary number.
 *
 * Return: Pointer to the modified buffer.
 */
char *move_left(char *a, int size, int num)
{
	int i;
	char *ptr;
	for (i = 0, ptr = (a + size - num); i < num; i++, ptr++)
		*(a + i) = *ptr;
	*(a + num) = '\0';
	return (a);
}
