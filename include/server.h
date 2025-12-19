#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdbool.h>
#include "eloop.h"

#define DEFAULT_PORT 6981

typedef struct SimpleKVServer {
    char *host;
    int port;
    bool enable_loop;
    EventLoop *el;
    int serverfd;
} SimpleKVServer;

/****************************************
 *              Declare.
 ***************************************/
extern SimpleKVServer server;


#endif
