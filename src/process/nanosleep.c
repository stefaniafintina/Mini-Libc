#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>


/*
->i found the function header from 
    ->https://man7.org/linux/man-pages/man2/nanosleep.2.html
->i got the function id from 
    ->https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
->Moreover i read more articles about this function to fully understand what it does:
    ->https://www.geeksforgeeks.org/c-nanosleep-function/
*/
int nanosleep(const struct timespec *req,
               struct timespec *rem) {
    int res = syscall(35, req, rem);
    if (res < 0) {
        errno = -res;
        return -1;
    } else {
        return res;
    }
}
