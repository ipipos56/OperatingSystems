#include <stdio.h>
#include <stdlib.h>

int main() {
    int sizeOfMemory = 10 * 1024 * 1024;
    for (int j = 0; j < 10; j++)
    {
        int *a;
        memset(a,0,sizeOfMemory);
        sleep(1);
    }
}
