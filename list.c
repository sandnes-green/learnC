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
        printf("分配失败，程序终止!\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    printf("请输入您需要生成链表节点的个数：len = ");
    scanf("%d", &len);
    for(i=0;i<len;i++)
    {
        printf("请输入第%d个节点的值:", i+1);
        scanf("%d", &val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew) {
            printf("分配失败，程序终止！\n");
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

bool insert_list(PNODE pHead, int pos,int val)
{
    int i = 0;
    int len = length_list(pHead);
    if(pos > len + 1 || pos <= 0)
    {
        printf("POS值不能小于零或大于%d!\n",len+1);
        return false;
    }
    PNODE p = pHead;
    while(NULL != p && i < pos-1)
    {
        p = p->pNext;
        i++;
    }
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("动态分配内存失败！\n");
        exit(-1);
    }
    pNew->data = val;
    pNew->pNext = p->pNext;
    p->pNext = pNew;
    return true;
}

void delete_list(PNODE pHead, int pos)
{
    int len = length_list(pHead);
    int i = 0;
    PNODE p = pHead;
    if(pos > len || pos <= 0)
    {
        printf("POS值不能小于零或大于%d!\n",len);
        return false;
    }

    while(NULL != p && i < pos-1)
    {
        p = p->pNext;
        i++;
    }
    p->pNext = p->pNext->pNext;
}

int main(void)
{
    PNODE pHead = NULL;
    pHead = create_list();

    int len = length_list(pHead);
    printf("链表长度为%d!\n",len);
    sort_list(pHead);
    traverse_list(pHead);
    insert_list(pHead,4,99);
    printf("%d\n",length_list(pHead));
    traverse_list(pHead);
    delete_list(pHead,3);
    traverse_list(pHead);
    /*
    if(is_empty(pHead)){
        printf("链表为空！\n");
    }else {
        printf("链表不为空！\n");
    }
    */
    return 0;
}

