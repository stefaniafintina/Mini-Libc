// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>


/*
->https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
->https://man7.org/linux/man-pages/man3/ftruncate.3p.html
*/
int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int res = syscall(77, fd, length);
	if (res < 0) {
		errno = -res;
		return -1;
	} else {
		return res;
	}
}
