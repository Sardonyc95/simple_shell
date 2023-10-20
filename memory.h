#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>


/* memory.c */
void *_reallocate(void *pointer, size_t old_size, size_t new_size);

/* free.c */
void free_memory_p(void *pointer);
void free_memory_pp(void **pointer);

#endif /* MEMORY_H */
