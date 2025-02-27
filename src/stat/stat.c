// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int res = syscall(4, path, buf);
	if (res < 0) {
		errno = -res;
		return -1;
	} else {
		return res;
	}
}
