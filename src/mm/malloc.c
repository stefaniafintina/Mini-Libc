// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


/*   I've got inspired from 
	https://stackoverflow.com/questions/8475609/implementing-your-own-malloc-free-with-mmap-and-munmap
	for both malloc and free functions, but i used the implemented functions for lists
	to save the size of the allocated memory, intead of saving it at the starting address
	 I've used man7 to get more details about the functions and their return values
*/
void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *start = mmap(0, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	mem_list_add(start, size);
	return start;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *start = malloc(nmemb * size);
	for (int i = 0; i < (int)nmemb; i++) {
		*((int *)start + i) = 0;
		/*initilize with 0 all the elements allocated */
	}
	return start;
}

void free(void *ptr)
{
	struct mem_list *elem = mem_list_find(ptr);
	if (elem == NULL) {
		return;
	}
    munmap(ptr, elem->len);
	mem_list_del(ptr);
}

/*
->https://docs.oracle.com/cd/E88353_01/html/E37843/reallocarray-3c.html
*/

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	free(ptr);
	ptr = malloc(size);
	if (ptr == NULL)
		errno = ENOMEM;
	return ptr;
}
void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	ptr = realloc(ptr, nmemb * size);
	if (ptr == NULL)
		errno = ENOMEM;
	return ptr;
}
