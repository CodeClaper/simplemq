#include <stdlib.h>
#include <sys/select.h>
#include "eloop.h"
#include "server.h"
#include "mm.h"

/* Create a file event. */
int CreateFileEvent(EventLoop *el, int fd, int mask, elFileProc *proc, void *privdata) {
    FileEvent *fe;

    /* Construct a FileEvent. */
    fe = instance(FileEvent);
    if (fe == NULL) return ELOOP_ERR;
    fe->fd = fd;
    fe->mask = mask;
    fe->proc = proc;
    fe->privdata = privdata;
    
    /* Append to fileEventHead. */
    if (el->fileEventHead) fe->next = el->fileEventHead;
    el->fileEventHead = fe;

    return ELOOP_OK;
}

/* Process event. */
void ProcessEvent(int flags) {
    int numkeys;

    /* If nothing, return back ASAP.*/
    if (flags && ELOOP_NONE) return;
    
}

/* The main entry for event loop. */
void EloopMain() {
    while (server.enable_loop) {
        ProcessEvent(ELOOP_ALL);
    }
}
