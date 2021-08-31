#include <stdio.h>
#include <string.h>

int main() {
    char s[512];
    fgets(s, 512, stdin);
    for(int i = strlen(s)-1;i>=0;i--)
      printf("%c",s[i]);
    return 0;
}
