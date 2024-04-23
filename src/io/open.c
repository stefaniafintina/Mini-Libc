// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>


/*
->to undersand how to use functions with a variable number of parametre i read 
the lab from PCLP1 where i find an exmaple of using this kind of functions
	->https://ocw.cs.pub.ro/courses/programare/laboratoare/lab13
->to understand the syscall reurn value i used:
	->https://man7.org/linux/man-pages/man2/open.2.html
*/
int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	va_list args;
	va_start(args, flags);
	/*
	->access modes are stored in mode
	->O_RDONLY, O_WRONLY, or O_RDWR
	*/
	int mode = va_arg(args, int);
	int res = syscall(2, filename, flags, mode);
	if (res < 0) {
		va_end(args);
		errno = -res;
		return -1;
	} else {
		va_end(args);
		return res;
	}
}
