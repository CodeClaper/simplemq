#ifndef __ELOOP_H__
#define __ELOOP_H__

#define ELOOP_OK    1
#define ELOOP_ERR   0

/* Eloop mask flags. */
#define ELOOP_NONE  0
#define ELOOP_READ  1
#define ELOOP_WRITE 2
#define ELOOP_ALL   4

struct EventLoop;

typedef void elFileProc(struct EventLoop *el, int fd, void *privdata);

/* Event loop control. */
typedef struct EventLoop {
    int maxfd;
    int numkeys;
    struct FileEvent *fileEventHead;
} EventLoop;

/* File event structure. */
typedef struct FileEvent {
    int fd;
    int mask;
    elFileProc *proc;
    void *privdata;
    struct FileEvent *next;
} FileEvent;

int CreateFileEvent(EventLoop *el, int fd, int mask, elFileProc *proc, void *privdata);
void ProcessEvent(int flags);
void EloopMain();

#endif
