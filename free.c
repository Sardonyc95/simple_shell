#include "memory.h"

/**
 * free_memory_p - Free a pointer
 *
 * @pointer: Pointer to free
 **/
void free_memory_p(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}

	pointer = NULL;
}

/**
 * free_memory_pp - Free a double pointer
 *
 * @pointer: Double pointer to free
 **/
void free_memory_pp(void **pointer)
{
	void **tmps;

	for (tmps = pointer; *tmps != NULL; tmps++)
		free_memory_p(*tmps);

	free_memory_p(pointer);
}
