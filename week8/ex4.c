#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int sizeOfMemory = 10 * 1024 * 1024;
    for (int i = 0; i < 10; i++) {
        void *a = malloc(sizeOfMemory);
        memset(a, 0, sizeOfMemory);
        struct rusage *usage = malloc(sizeof(struct rusage));
        getrusage(RUSAGE_SELF, usage);
        printf("ru_maxrss: %ld\n", usage->ru_maxrss);
        sleep(1);
    }
}
