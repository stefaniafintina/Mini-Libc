// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>


/* 
For the implementation of the following functions i used some resources :
->to get the id of each function: https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
->additional information about mmap:
	->https://www.ibm.com/docs/ja/i/7.2?topic=ssw_ibm_i_72/apis/mmap.html
	->https://man7.org/linux/man-pages/man2/mmap.2.html
->i used the "man7" for a more detailed explation about each funcion
*/
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long long res = syscall(9, addr, length, prot, flags, fd, offset);
	/*The call returns the actual address in memory where the mapping begins. */
	if (res < 0) {
		errno = -res;
		return MAP_FAILED;
	} else {
		return (void *)res;
	}
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long long res = syscall(25, old_address, old_size, new_size, flags);
	if (res < 0) {
		errno = -res;
		return MAP_FAILED;
	} else {
		return (void *)res;
	}
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	long long res = syscall(11, addr, length);
	if (res < 0) {
		errno = -res;
		return -1;
	} else {
		return 0;
	}
}
