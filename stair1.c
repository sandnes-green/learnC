#include <stdio.h>

int main(void) {
    int i,j;
    int x;

    printf("要显示多少行?\n");
    scanf("%d", &x);

    for(i=0;i<x;i++) {
        for(j=0;j<i;j++) {
            putchar(' ');
        }
        printf("%d\n", i % 10);
    }
    return 0;
}
