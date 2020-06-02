#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE, *PNODE;

bool is_empty(PNODE pHead)
{
    if(pHead->pNext == NULL){
        return true;
    }else {
        return false;
    }
}

int length_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    int len = 0;
    while(NULL != p) {
        len++;
        p = p->pNext;
    }
    return len;
}


PNODE create_list(void)
{
    int len;
    int i;
    int val;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(NULL == pHead)
    {
        printf("����ʧ�ܣ�������ֹ!\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    printf("����������Ҫ��������ڵ�ĸ�����len = ");
    scanf("%d", &len);
    for(i=0;i<len;i++)
    {
        printf("�������%d���ڵ��ֵ:", i+1);
        scanf("%d", &val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew) {
            printf("����ʧ�ܣ�������ֹ��\n");
            exit(-1);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while(NULL != p)
    {
        printf("%d\n",p->data);
        p = p->pNext;
    }
    printf("\n");
    return;
}
void sort_list(PNODE pHead)
{
    int i,j,t;
    PNODE p,q;
    int len = length_list(pHead);
    for(i=0,p = pHead->pNext;i<len-1;i++,p = p->pNext) {
        for(j=i+1,q = p->pNext; j<len;j++,q = q->pNext) {
            if(p->data > q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
    return;
}

int main(void)
{
    PNODE pHead = NULL;
    pHead = create_list();

    int len = length_list(pHead);
    printf("������Ϊ%d!\n",len);
    sort_list(pHead);
    traverse_list(pHead);
    /*
    if(is_empty(pHead)){
        printf("����Ϊ�գ�\n");
    }else {
        printf("����Ϊ�գ�\n");
    }
    */
    return 0;
}

