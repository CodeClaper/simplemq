#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdbool.h>
#include "eloop.h"

#define VERSION "0.0.1"
#define DEFAULT_PORT 6981

typedef struct SimpleKVServer {
    char *host;
    int port;
    char *version;
    int serverfd;
    EventLoop *el;
} SimpleKVServer;

/****************************************
 *              Declare.
 ***************************************/
extern SimpleKVServer server;


#endif
