#ifndef _ERRNO_H
#define _ERRNO_H
#define EOSERR -1
#define ENOERR 0
#define EPERM 1
#define ENOENT 2
#define ESRCH 3
#define EINTR 4
#define EIO 5
#define ENXIO 6
#define E2BIG 7
#define ENOEXEC 8
#define EBADF 9
#define ECHILD 10
#define EAGAIN 11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14
#define ENOTBLK 15
#define EBUSY 16
#define EEXIST 17
#define EXDEV 18
#define ENODEV 19
#define ENOTDIR 20
#define EISDIR 21
#define EINVAL 22
#define ENFILE 23
#define EMFILE 24
#define ENOTTY 25
#define ETXTBSY 26
#define EFBIG 27
#define ENOSPC 28
#define ESPIPE 29
#define EROFS 30
#define EMLINK 31
#define EPIPE 32
#define EDOM 33
#define ERANGE 34
#define EDEADLK 35
#define ENAMETOOLONG 36
#define ENOLCK 37
#define ENOSYS 38
#define ENOTEMPTY 39
#define ENOTSOCK 40
#define EDESTADDRREQ 41
#define EMSGSIZE 42
#define EPROTOTYPE 43
#define ENOPROTOOPT 44
#define EPROTONOSUPPORT 45
#define ESOCKTNOSUPPORT 46
#define EOPNOTSUPP 47
#define EPFNOSUPPORT 48
#define EAFNOSUPPORT 49
#define EADDRINUSE 50
#define EADDRNOTAVAIL 51
#define ENETDOWN 52
#define ENETUNREACH 53
#define ENETRESET 54
#define ECONNABORTED 55
#define ECONNRESET 56
#define ENOBUFS 57
#define EISCONN 58
#define ENOTCONN 59
#define ESHUTDOWN 60
#define ETOOMANYREFS 61
#define ETIMEDOUT 62
#define ECONNREFUSED 63
#define EHOSTDOWN 64
#define EHOSTUNREACH 65
#define EALREADY 66
#define EINPROGRESS 67
extern int errno;
extern int sys_nerr;
extern char *sys_errlist[];
#endif
