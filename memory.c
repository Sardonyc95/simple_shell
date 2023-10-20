#include "memory.h"

/**
 * _reallocate - Reallocates a memory block using malloc and free
 *
 * @pointer: Pointer to the memory previously allocated
 * @old_size: Size, in bytes, of the allocated space for ptr
 * @new_size: New size, in bytes of the new memory block
 *
 * Return: Memory reallocated
 **/
void *_reallocate(void *pointer, size_t old_size, size_t new_size)
{
	char *z, *aux;
	unsigned int b;

	if (new_size == old_size)
		return (pointer);

	if (pointer == NULL)
	{
		z = malloc(new_size);
		if (z == NULL)
			return (NULL);

		return (z);
	}

	if (new_size == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}

	z = malloc(new_size);
	if (z == NULL)
		return (NULL);

	aux = pointer;
	for (b = 0; b < old_size; b++)
		z[b] = aux[b];

	free(pointer);

	return (z);
}
