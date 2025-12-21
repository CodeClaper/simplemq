#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdbool.h>
#include "eloop.h"
#include "slog.h"

#define VERSION "0.0.1"
#define DEFAULT_PORT 6981
#define BUFF_SIZE 1024

typedef struct SimpleMQServer {
    char *host;
    int port;
    char *version;
    int serverfd;
    EventLoop *el;
    LLevel llevel;
    char *logDir;
} SimpleMQServer;

/****************************************
 *              Declare.
 ***************************************/
extern SimpleMQServer server;


#endif
