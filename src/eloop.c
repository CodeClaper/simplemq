#include "eloop.h"
#include "server.h"
#include <sys/select.h>

/* Process event. */
static void ProcessEvent(int flags) {
    int numkeys;

    /* If nothing, return back ASAP.*/
    if (flags && AE_NONE) return;
    
}

/* The main entry for event loop. */
void EloopMain() {
    while (server.enable_loop) {
        ProcessEvent(AE_ALL);
    }
}
