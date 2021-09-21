#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t prodThread, consThread;

int producerAlive = 1, consumerAlive;

int bs = 0;
const int LIMIT = 1e2;
int iterationProducer = 0, iterationConsumer = 0;

void condWait(int *c) {
    while (!*c) {
        usleep(100);
    }
}

void condSignal(int *c) {
    *c = 1;
}

void *produce() {
    while (1) {
        if (iterationProducer % 1000 == 0) {
            printf("Producer: %d\n", iterationProducer);
        }
        if (bs == LIMIT || !producerAlive) {
            producerAlive = 0;
            condWait(&producerAlive);
        }
        bs++;
        if (bs == 1) {
            condSignal(&consumerAlive);
        }
        iterationProducer++;
    }
}

void *consume() {
    while (1) {
        if (iterationConsumer % 1000 == 0) {
            printf("Consumer: %d\n", iterationConsumer);
        }
        if (bs == 0 || !consumerAlive) {
            consumerAlive = 0;
            condWait(&consumerAlive);
        }
        bs--;
        if (bs == LIMIT - 1) {
            condSignal(&producerAlive);
        }
        iterationConsumer++;
    }
}

int main() {
    pthread_create(&prodThread, NULL, produce, NULL);
    pthread_create(&consThread, NULL, consume, NULL);
    pthread_join(prodThread, NULL);
    pthread_join(consThread, NULL);

    return 0;
}
