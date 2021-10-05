#include <stdio.h>
#include <stdlib.h>

int main() {
    //initializing of s
    char **s = malloc(12 * sizeof(char));
    char foo[] = "Hello World";
    *s = foo;
    //pointer to string interpreted as string
    printf("s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %c\n", *s[0]);
    //make pointer free, for the sake of consistency
    free(s);
    return (0);
}
