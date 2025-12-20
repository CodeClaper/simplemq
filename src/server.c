#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "common.h"
#include "config.h"
#include "anet.h"
#include "eloop.h"
#include "err.h"
#include "mm.h"

SimpleKVServer server;

/* Server socket accept process.*/
static void ServerAcceptProc(struct EventLoop *el, int fd, int mask, void *privdata) {
    int cfd, clientPort;
    char clientIp[128];

    UNUSED(el);
    UNUSED(mask);
    UNUSED(privdata);

    cfd = ServerAccept(fd, clientIp, &clientPort);
    if (cfd == ANET_ERR) ThrowErr("Accept fail."); 
    printf("Accepted %s:%d\n", clientIp, clientPort);
}

/* Init the server. */
static void InitServer() {
    server.host = NULL;
    server.port = DEFAULT_PORT;
    server.serverfd = -1;
    server.el = instance(EventLoop);
    server.el->numkeys = 0;
    server.el->maxfd = 0;
    server.el->fileEventHead = NULL;
    server.el->stop = false;
}


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
    retval = CreateFileEvent(server.el, fd, ELOOP_READABLE, ServerAcceptProc,  NULL);
    if (retval == ANET_ERR) ThrowErr("Create file event fail.");
    server.serverfd = fd;
}

/* The main entry of server.  */
int main(int argc, char *argv[]) {
    InitServer();
    ConfigServer();
    SetupServer();
    EloopMain(server.el);
    return 0;
}
