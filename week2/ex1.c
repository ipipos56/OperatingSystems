#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int integerValue = INT_MAX;
    float floatValue = FLT_MAX;
    double doubleValue = DBL_MAX;

    printf("Integer ", sizeof(int), integerValue);
    printf("Float ", sizeof(float), floatValue);
    printf("Double ", sizeof(double), doubleValue);
    return 0;
}
