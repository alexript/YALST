/*
	Little Smalltalk, version 3
	Main Driver
	written By Tim Budd, September 1988
	Oregon State University
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/common.h"
#include "src/memory.h"
#include "src/names.h"
#include "src/tty.h"
#include "src/unixio.h"
#include "src/interp.h"



static const char *
getScript(int *argc, char **argv) {
    const char *script = NULL;

    int dest = 0;
    for (int src = 0; src < *argc; src++) {
        if (streq("-e", argv[src])) {
            if (src + 1 >= *argc) {
                sysError("Trailing '-p' argument.", "");
                exit(1);
            }

            src++;
            script = argv[src];
            continue;
        }

        argv[dest] = argv[src];
        ++dest;
    }

    *argc = dest;
    return script;
}



static void
run() {
    object firstProcess;

    firstProcess = globalSymbol("systemProcess");
    if (firstProcess == nilobj) {
        sysError("no initial process", "in image");
        exit(1);
        return;
    }

    while (execute(firstProcess, 15000)) {
        // ...
    }

    /* exit and return - belt and suspenders, but it keeps lint happy */
    exit(0);
}// run


int
st_main() {
    FILE *fp;
    char *p, buffer[120];

    initMemoryManager();

    strcpy(buffer, "systemImage");
    p = buffer;

    fp = fopen(p, "rb");

    if (fp == NULL) {
      sysError("cannot open image", p);
      exit(1);
    }

    imageRead(fp);
    initCommonSymbols();

    printf("Little Smalltalk, Version 3.1(r)\n");
    printf("Written by Tim Budd (Oregon State University) and contributers.\n");


    run();

    return 0;
}
