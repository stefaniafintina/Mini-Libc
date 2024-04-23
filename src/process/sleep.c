#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>

/*
->to implement these function i neededd o know the parametres of struct timspac
    because nanosleep uses both minutes and seconds, but in this case we needed only seconds, 
    so had to make some initializations
->https://man7.org/linux/man-pages/man3/timespec.3type.html
->https://man7.org/linux/man-pages/man3/sleep.3.html
->https://www.geeksforgeeks.org/sleep-function-in-c/
*/
unsigned int sleep(unsigned int seconds)
{
    struct timespec x, y;
    x.tv_sec = 0;
    x.tv_nsec = 0;
    y.tv_nsec = 0;
    y.tv_sec = seconds;
    int res = nanosleep(&y, &x);
    if (res >= 0) {
        return 0;
    } else {
        return x.tv_sec;
    }
}
