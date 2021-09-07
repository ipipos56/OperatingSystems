#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *firstElementPointer, int length)
{
    for(int i = 0;i<length-1;i++)
        for(int j = 0;j<length-1;j++)
        {
            if(firstElementPointer[j+1] < firstElementPointer[j])
            {
                swap(&firstElementPointer[j+1], &firstElementPointer[j]);
            }
        }
}

int main()
{
    int arrayTest[6] = {2,4,1,6,8,3};
    bubble_sort(arrayTest,6);
    for(int i = 0;i<6;i++)
        printf("%d ",arrayTest[i]);
}
