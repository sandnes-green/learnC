#include <stdio.h>

typedef int ZHANGSAN;
typedef struct Student {
    int sid;
    char name[100];
    char sex;
}ST;

int main(void) {
//    struct Student st;
//    struct Student * ps = &st;
    ST st2;
    st2.sid = 200;
    printf("%d\n",st2.sid);
    return 0;
}
