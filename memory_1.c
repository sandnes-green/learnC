#include <stdio.h>
#include <malloc.h>
struct Student {
    int sid;
    int age;
};

struct Student * CreateStudent(void);
void ShowStudent(struct Student *);

int main(void) {
    struct Student * ps;

    ps = CreateStudent();
    ShowStudent(ps);

    return;
}
struct Student * CreateStudent(void) {
    struct Student *p = (struct Student *)malloc(sizeof(struct Student));
    p->age = 88;
    p->sid = 99;
    return p;
}
void ShowStudent(struct Student *pst) {
    printf("%d %d\n", pst->sid, pst->age);
}
