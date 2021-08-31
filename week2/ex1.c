#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int integerValue = INT_MAX;
    float floatValue = FLT_MAX;
    double doubleValue = DBL_MAX;

    printf("Integer: %lu %d ", sizeof(int), integerValue);
    printf("Float: %lu %f ", sizeof(float), floatValue);
    printf("Double: %lu %f ", sizeof(double), doubleValue);
    return 0;
}
