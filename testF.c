#include <stdio.h>

void main(void) {
    double sum;
    int i;
    for(i = 0; i < 99; i++) {
        sum += 0.1;
    }
    printf("%f\n", sum);
}
