#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int countOfStars = 1;
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<(2*n-1)/2-countOfStars/2;j++)
            printf("%s"," ");
        for(int j = 0;j<countOfStars;j++)
            printf("%s","*");
        printf("%s","\n");
        countOfStars+=2;
    }
    return 0;
}
