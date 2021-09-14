#include <stdio.h>
#include <unistd.h>

int n;

int main() {
    int res = fork();
    if (res == 0)
        printf("Hello from child %d\n", getpid() - n);
    else
        printf("Hello from parent %d\n", getpid() - n);
}
