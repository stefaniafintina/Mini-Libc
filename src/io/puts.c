#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

/*
->https://man7.org/linux/man-pages/man3/puts.3.html
->this function is a "fancy" printf which prints a "\n"
  a the end of printing 
->to make it possible i used a syscall 
  which make a basic write and another one to put a "\n" at the end
*/

int puts(const char *s)
{
    syscall(1, 1, s, strlen(s));
    return syscall(1, 1, "\n", strlen("\n"));
}
