#include <pthread.h>
#include <stdio.h>

void* functionInThread(void* param) {
    pthread_exit(0);
}

int main () {
    pthread_t tid;
    for (int i = 0; i < 5; i++) {
        pthread_create(&tid, NULL, functionInThread, (void *) &i);
        printf("Created thread: %d\n", i);
        pthread_join(tid, NULL);
    }
}
