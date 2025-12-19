#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdbool.h>
#include "eloop.h"

typedef struct SimpleKVServer {
    char *host;
    int port;
    bool enable_loop;
    EventLoop el;
} SimpleKVServer;

/****************************************
 *              Declare.
 ***************************************/
extern SimpleKVServer server;


#endif
