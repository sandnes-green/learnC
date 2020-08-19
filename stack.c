#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK, * PSTACK;

void init(PSTACK);
bool pop(PSTACK,int *);
void clear(PSSTACK);
int main(void)
{
    int val;
    STACK S;
    init(&S);
    pushStack(&S,6);
    pushStack(&S,4);
    pushStack(&S,3);
    pushStack(&S,2);
    pushStack(&S,1);
    //if(pop(&S, &val))
    //{
     //   printf("出栈成功，出栈的元素是%d\n",val);
    //}
    //else
   // {
      //  printf("出栈失败！\n");
    //}
    traverse(&S);
    clear(&S);
    traverse(&S);
    return 0;
}

void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("动态分配内存失败！\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }
  //  PNODE pHead = (PNODE)malloc(sizeof(NODE));
}

void pushStack(PSTACK PS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = PS->pTop;
    PS->pTop = pNew;

    return;
}

void traverse(PSTACK PS)
{
    PNODE p = PS->pTop;
    while(PS->pBottom != p)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
}

bool empty(PSTACK pS)
{
    if(pS->pTop == pS->pBottom)
        return true;
    else
        return false;
}

bool pop(PSTACK pS,int * pVal)
{
    if(empty(pS)){
        return false;
    }
    else {
        PNODE r = pS->pTop;
        *pVal = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;
        return true;
    }
}
void clear(PSTACK pS)
{
    if(empty(pS))
    {
        return;
    }else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;
        while(p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottom;
    }
}

