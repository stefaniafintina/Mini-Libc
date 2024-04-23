// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

/*
->https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
->https://man7.org/linux/man-pages/man2/lseek.2.html
*/

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	int res = syscall(8, fd, offset, whence);
	if (res < 0) {
		errno = -res;
		return -1;
	} else {
		return res;
	}
}
