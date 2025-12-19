#ifndef __ELOOP_H__
#define __ELOOP_H__

#define AE_NONE     0
#define AE_READ     1
#define AE_WRITE    2
#define AE_ALL      4

typedef struct EventLoop {
    int maxfd;
    int numkeys;
} EventLoop;

#endif
