#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
struct Arr
{
    int * pBase;
    int len;
    int cnt;
  //  int increment;
};

void init_arr(struct Arr * pArr, int length);
bool append_arr(struct Arr * pArr, int val);
bool insert_arr(struct Arr * pArr, int pos, int val);
bool delete_arr(struct Arr * pArr, int pos, int * val);
//int get();
bool is_empty(struct Arr *);
bool is_full(struct Arr* pArr);
void sort_arr(struct Arr *);
void show_arr(struct Arr *);
void inversion_arr(struct Arr *);

int main(void) {
    struct Arr arr;
    int val;

    init_arr(&arr, 6);
    show_arr(&arr);
    append_arr(&arr,77);
    append_arr(&arr,12);
    append_arr(&arr,132);
    append_arr(&arr,2);
//    if(delete_arr(&arr, 1, &val)) {
//        printf("删除成功！\n");
//        printf("您删除的元素是:%d\n", val);
//    }else {
//        printf("删除失败！\n");
//    }
    sort_arr(&arr);
    show_arr(&arr);
    inverion_arr(&arr);
    show_arr(&arr);
    return 0;
}


void init_arr(struct Arr* pArr, int length) {
    pArr->pBase = (int *)malloc(sizeof(int) *length);
    if(NULL == pArr->pBase) {
        printf("动态内存分配失败！\n");
        exit(-1);
    }else {
        pArr->len = length;
        pArr->cnt = 0;
    }
    return;
}
bool is_empty(struct Arr* pArr) {
    if(0 == pArr->cnt) {
        return true;
    }else {
        return false;
    }
}
bool is_full(struct Arr* pArr) {
    if(pArr->len == pArr->cnt) {
        return true;
    }else {
        return false;
    }
}
bool insert_arr(struct Arr * pArr, int pos, int val) {
    int i;

    if(is_full(pArr)) {
        return false;
    }
    if(pos < 1 || pos>pArr->cnt + 1) {
        return false;
    }


    for(i = pArr->cnt-1; i>pos-1; --i) {
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos-1] = val;
    pArr->cnt++;
    return true;
}
bool append_arr(struct Arr * pArr, int val) {
    if(is_full(pArr)) {
        printf("数组已满！\n");
    }else {
        pArr->pBase[pArr->cnt++] = val;

        return true;
    }
}
bool delete_arr(struct Arr * pArr, int pos, int * val) {
    if(is_empty(pArr)) {
        return false;
    }
    if(pos<1 || pos>pArr->cnt) {
        return false;
    }

    int i;
    *val = pArr->pBase[pos-1];
    for(i = pos; i<pArr->cnt; i++) {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    pArr->cnt--;
    return true;
}
void show_arr(struct Arr * pArr) {
    if(is_empty(pArr)) {
        printf("数组为空！\n");
    }else {
        for(int i = 0; i<pArr->cnt; ++i) {
            printf("%d\n", pArr->pBase[i]);
        }
    }
}

void inverion_arr (struct Arr * pArr) {
    int i = 0;
    int j = pArr->cnt-1;
    int t;
    while (i < j) {
      t = pArr->pBase[i];
      pArr->pBase[i] = pArr->pBase[j];
      pArr->pBase[j] = t;
      i++;
      j--;
    }
}

void sort_arr(struct Arr * pArr) {
    int i,j,t;
    for(i = 0; i<pArr->cnt; i++) {
        for(j = i+1; j<pArr->cnt;j++) {
            if(pArr->pBase[i] > pArr->pBase[j]) {
                t = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = t;
            }
        }
    }
}
