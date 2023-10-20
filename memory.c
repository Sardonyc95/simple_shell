#include "memory.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 *
 * @ptr: Pointer to the memory previously allocated
 * @old_size: Size, in bytes, of the allocated space for ptr
 * @new_size: New size, in bytes of the new memory block
 *
 * Return: Memory reallocated
 **/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *c, *aux;
	unsigned int x;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		c = malloc(new_size);
		if (c == NULL)
			return (NULL);

		return (c);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	c = malloc(new_size);
	if (c == NULL)
		return (NULL);

	aux = ptr;
	for (x = 0; x < old_size; x++)
		c[x] = aux[x];

	free(ptr);

	return (c);
}
