#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    free(a);
}
