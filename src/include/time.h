/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef	__STRING_H__
#define	__STRING_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

/*
->https://man7.org/linux/man-pages/man2/nanosleep.2.html
->https://man7.org/linux/man-pages/man3/sleep.3.html
->https://man7.org/linux/man-pages/man3/timespec.3type.html
*/

struct timespec {
    long tv_sec;   /* Seconds */
    long tv_nsec;  /* Nanoseconds [0, 999'999'999] */
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);

#ifdef __cplusplus
}
#endif

#endif
