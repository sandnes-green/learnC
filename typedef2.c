#include <stdio.h>

typedef struct Student {
    int sid;
    char name[100];
    char sex;
}* PST;

int main(void) {
    struct Student st;
    PST ps = &st;
    ps->sid = 99;

    printf("%d\n", ps->sid);
    return 0;
}
