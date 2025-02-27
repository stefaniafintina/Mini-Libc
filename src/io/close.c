// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	int res = syscall(3, fd);
	if (res < 0) {
		errno = -res;
		return -1;
	} else {
		return res;
	}
}

