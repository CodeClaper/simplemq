#include <stdlib.h>
#include "server.h"
#include "config.h"
#include "anet.h"
#include "eloop.h"
#include "err.h"

SimpleKVServer server;

/* Config the server. */
static void ConfigServer() {
    /* Load from config file. */
    LoadConfigFile();
}

/* Setup the server. */
static void SetupServer() {
    int fd, retval;

    fd = CreateTcpServer(server.host, server.port);
    if (fd == ANET_ERR) ThrowErr("Create tcp socket server fail.");
    retval = CreateFileEvent(server.el, fd, ELOOP_READ, NULL,  NULL);
    if (retval == ANET_ERR) ThrowErr("Create file event fail.");
    server.serverfd = fd;
}

/* The main entry of server.  */
int main(int argc, char *argv[]) {
    ConfigServer();
    SetupServer();
    EloopMain();
    return 0;
}
