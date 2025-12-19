#include <stdio.h>
#include "server.h"
#include "config.h"

SimpleKVServer server;

static void ConfigServer() {
    /* Load from config file. */
    LoadConfigFile();
}

/* The main entry of server.  */
int main(int argc, char *argv[]) {
    ConfigServer();
    printf("Hello world, welcom to SimpleMQ.\n");
    return 0;
}
