#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int integerValue = INT_MAX;
    float floatValue = FLT_MAX;
    double doubleValue = DBL_MAX;

    printf("Integer: %lu %d \n", sizeof(int), integerValue);
    printf("Float: %lu %f \n", sizeof(float), floatValue);
    printf("Double: %lu %f \n", sizeof(double), doubleValue);
    return 0;
}
